//import { act } from '@testing-library/react';
import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import Board from './Board.js'
import { Piece} from './const.js'

export default function Square(props) {
    return (
        <button className={'square ' + props.className} onClick={props.onClick}>
            
            {props.piece === Piece.queen && <i className="fas fa-chess-queen fa-2x"></i>}
            {props.piece === Piece.king && <i className="fas fa-chess-king fa-2x"></i>}
            {props.piece === Piece.tour && <i className="fas fa-chess-rook fa-2x"></i>}
            {props.piece === Piece.fou && <i className="fas fa-chess-bishop fa-2x"></i>}
            {props.piece === Piece.horse && <i className="fas fa-chess-knight fa-2x"></i>}
            {props.piece === Piece.pion && <i className="fas fa-chess-pawn fa-2x"></i>}
            
        </button>
    );
}


export function ButtonNewGame(props) {
    return (
        <button className="btn btn-info" onClick={props.onClick}>
            Nouvelle partie
        </button>
       
    );
}


export function RangeSelector(props) {
    return (
        <div>
            <label
                for="customRange2"
                className="form-label">Deep search : {props.value}
            </label>
            <input
                value={props.value }
                type="range"
                className="form-range"
                min={props.min}
                max={props.max}
                onChange={props.onChange}
                id="customRange2">
             </input>
       </div>
    );
}


export function Option(props) {

    return (
        <div className="status">
            <ButtonNewGame onClick={props.newGameOnClick} />
            <RangeSelector
                value={props.deepSearchValue}
                min={1}
                max={5}
                onChange={props.deepRangeOnChange}
            />
        </div>
    );
}

class Game extends React.Component {
    render() {
        return (
            <Board />
        );
    }
}

// ========================================

ReactDOM.render(
    <Game />,
    document.getElementById('root')
);
