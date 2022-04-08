//import { act } from '@testing-library/react';
import React from 'react';
//import ReactDOM from 'react-dom';
import './index.css';
import { Player, GameStatus } from './const.js';
import Square, { ButtonNewGame, Option } from './index.js';

export default class Board extends React.Component {
    constructor(props) {
        super(props);

        this.new_game = this.new_game.bind(this);

        this.state = {
            board: null,
            selected: null,
            previews: [],   // c'est la liste de previews
            previewed: [],  // c'est les casse qui doivent être en previews
            player_one_is_next: true,
            piece_player_one: 0,
            piece_player_two: 0,
            game_status: undefined,
            deep_search: 2
        };

        console.log("set to 16")
    }

    componentDidMount() {
        fetch('http://0.0.0.0:8000/api/pull_game')
            .then(response => response.json())
            .then(data => {
                console.log("Data receive")

                //const board_data = data[0];
                console.log("next player : " + data["player_one_is_next"]);


                this.setState({
                    game_status: data["game_status"],
                    piece_player_one: data["piece_player_one"],
                    piece_player_two: data["piece_player_two"],
                    board: data["board"],
                    previews: data["previews"],
                    player_one_is_next: data["player_one_is_next"]
                })
            })
    }

    deplacement(to_x, to_y) {
        console.log("Coup valide .... déplacement");

        const [from_x, from_y] = [this.state.selected[0], this.state.selected[1]]

        // Déplacement de pion
        let new_board = this.state.board;
        new_board[to_y][to_x] = new_board[from_y][from_x];
        new_board[from_y][from_x] = null;
        console.log("Pion déplacé");


        /*
         On pourrais se passer de se setState mais j'ai peur que si l'ordi prend trop de temps a répondre
         il y ai un décalage entre notre pièce qui se déplace  et les deux se déplacerai instantanément
        */
        this.setState({
            board: new_board,
            previewed: null,
            previews: null,
            selected: null,
            player_one_is_next: true // pour empéche de pouvoir cliqué sur un case si l'ordi calcul
        }, () => {

            // Une fois le setState terminé
            let push_url = "http://0.0.0.0:8000/api/push_game?" +
                "to_x=" + (to_x) + "&to_y=" + (to_y) +
                "&from_x=" + (from_x) + "&from_y=" + (from_y) +
                "&deep_search=" + this.state.deep_search;
            console.log("Déplacement perso de " + from_x + ":" + from_y + " vers " + to_x + ":" + to_y);
        
            fetch(push_url)
                .then(response => response.json())
                .then(data => {
                
                    console.log("Donnée recus : ");
                    console.log(data);

                // Vérification de la bonne réception du jeux
                    if (data["game_status"] === GameStatus.FAILED) {
                    
                        this.setState({
                            game_status: GameStatus.FAILED
                        });
                        // A faire : afficher un pop up d'erreur
                    } else {
                        let new_board = this.state.board;
                        // On effectue le coups qu'a éxécuté l'orinateur sauf si le coup que l'on vient de
                        // faire nous a fait gagné
                        
                        if (data["game_status"] !== GameStatus.P_TWO_WIN) {
                            const [from_x, from_y] = [data["from_x"], data["from_y"]];
                            const [to_x, to_y] = [data["to_x"], data["to_y"]];
            
                            new_board[to_y][to_x] = new_board[from_y][from_x];
                            new_board[from_y][from_x] = null;
    
                            console.log("Déplacement de  " + from_x + ":" + from_y + " vers " + to_x +":"+ to_y);
                        }
    
                        this.setState({
                            game_status: data["game_status"],
                            previews: data["previews"],
                            board: new_board,
                            player_one_is_next: false,
                            piece_player_one: data["piece_player_one"],
                            piece_player_two: data["piece_player_two"],
                        });
                    }       
            })
        });
    }


    handleClick(x, y) {
        // Si selected != null alors on à déjà sélectionner une casse
        // maintenant on va vérifié que la casse sélectionnée est correctes.
        // Pour ce faire on vérifie simplement qu'elle se trouve dans le preview.
        console.log("Cliqué à la position : x : " + x + " y : " + y);

        // DEBUG FORCAGE DU MOUVEMENT
        //if (this.state.selected)
         //   this.deplacement(x, y);

        if (this.state.selected &&  this.state.previewed && this.state.previewed.some(x_y => x === x_y[0] && y === x_y[1])) {
            this.deplacement(x, y);
        } else {
            // On vérifie qu'on a bien cliqué sur une casse qui comporte un pion
            // et que ce pion nous appartient
            if (this.state.board[y][x]) {
                const clicked_to_player = this.state.board[y][x][1];

                if ((this.state.player_one_is_next && clicked_to_player === Player.player_two) ||
                    (!this.state.player_one_is_next && clicked_to_player === Player.player_one)) {
                    
                    console.log("Casse cliquée invalide");
                    console.log("joueur suivant : " + this.state.player_one_is_next);
                    console.log("Cliqué sur : " + clicked_to_player);
                    console.log("exp 1 : " + this.state.player_one_is_next && clicked_to_player === Player.player_one);
                    console.log("exp 2 : " + !this.state.player_one_is_next && clicked_to_player === Player.player_two);
                    return;
                }

                /* 
                Il faut s'assuré que le state.previews ne soit pas vide, 
                ca peux arrivé si l'oridnateur met trop de temps a réponde
                */
                
                if (this.state.previews) {
                    this.setState({
                        previewed: this.state.previews[y][x],
                        selected: [x, y]
                    },
                        console.log(this.state.previewed)
                    );
                }
            } 
        }
    }


    renderSquare(x, y, square_color) {

        let className = square_color;
        let piece = undefined;

        if (this.state.selected && this.state.selected[0] === x && this.state.selected[1] === y) {
            className += ' square_selected';
        }

        if (this.state.board && this.state.board[y][x]) {
            
            piece = this.state.board[y][x][0];

            if (this.state.board[y][x][1] === Player.player_one) {
                className += ' dark_piece';
            } else {
                className += ' light_piece';
            }
        }

        if (this.state.previewed && this.state.previewed.some(x_y => x === x_y[0] && y === x_y[1])) {
            className += ' possibility';
        }

        return (
            <Square
            piece={piece}
            className={className}
            onClick={() => this.handleClick(x, y)}
            />
        );
    }
    
    
    renderRow(y) {
        
        let row_content = [];
        let square_color = (y % 2 === 0) ? 'light_square' : 'dark_square';

        for (let x = 0; x < 8; x++) {
            row_content.push(this.renderSquare(x, y, square_color));
            square_color = (square_color === 'dark_square') ? 'light_square' : 'dark_square';
        }

        return row_content;
    }

    new_game(test) {
        console.log("Nouevelle partie...")

        fetch('http://0.0.0.0:8000/api/new_game')
            .then(response => response.json())
            .then(data => {
            
                //const board_data = data[0];
                //console.log(board_data);

                this.setState({
                    game_status: data["game_status"],
                    piece_player_one: data["piece_player_one"],
                    piece_player_two: data["piece_player_two"],
                    board: data["board"],
                    previews: data["previews"],
                    selected: null,
                    previewed: null,
                    player_one_is_next: data["player_one_is_next"]
                })
            });
    }

    handleDeepSearchRange(event) {
        console.log("nouvelle valeur : " + event.target.value);
        this.setState({
            deep_search: event.target.value
        })
    }

    render() {
        
        const next_player = (this.state.player_one_is_next) ?  "L'ordinateur joue" : "A vous de jouer";
        let board_content = [];

        board_content.push(<div className="status">{next_player}</div>);
        board_content.push(<div className="status">Joueur blanc : {this.state.piece_player_two} pièces restantes</div>);
        board_content.push(<div className="status">Joueur noir  : {this.state.piece_player_one} pièces restantes</div>);

        console.log("status : " + this.state.game_status)

        if (this.state.game_status === GameStatus.P_TWO_WIN) {
            board_content.push(
                <div className="alert alert-success">
                    <strong>Success!</strong> Indicates a successful or positive action.
                        <ButtonNewGame
                        onClick={() => this.new_game()}
                        />
                </div>
            );
        } else if (this.state.game_status === GameStatus.P_ONE_WIN) {
            board_content.push(
                <div className="alert alert-warning">
                    <strong>Success!</strong> Indicates a successful or positive action.
                        <ButtonNewGame
                        onClick={() => this.new_game()}
                        />
                </div>
            );
        } else if (this.state.game_status === GameStatus.FAILED) {
            board_content.push(
                <div className="alert alert-warning">
                    <strong>Erreur!</strong> Erreur liée à l'API.
                </div>
            );
        }

        for (let y = 0; y < 8; y++) {
            board_content.push(
                <div className="board-row">
                    {this.renderRow(y)}
                </div>
            )
        }

        return (
            <div className="game">
                <div className="game-board">
                    { board_content}
                </div>
                <div className="game-option">
                    <Option
                        newGameOnClick={() => this.new_game()}
                        deepRangeOnChange={(event) => this.handleDeepSearchRange(event)}
                        deepSearchValue={ this.state.deep_search }
                    />
                </div>
            </div>
        );
                
    }
}
