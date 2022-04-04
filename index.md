# Explication de mes projects

## LesTouristesOdooHackathon
[**Lien Github**](https://github.com/Xander-Br/LesTouristesOdooHackathon/tree/ai)

Obtention d'un score messurant l'attention via l'analyse des expression faciales, du regards  et des mouvements de têtes

### Fonctionnement

Lors d'un appel vidéo on ligne :
- Capture de la vidéo via Selenium
- Découpage des frames et analyse grâce à de l'IA via 3 classifier différents : 
  -  Head pose estimation (Tensorflow)
  -  Eye-tracking (Dlib)
  -  Expression recognition (PyTorch)
-  Calcule d'un score d'attention en fonction des résultats obtenu
-  Mise à disposition serveur - client via une API (Flask)
-  Add-on coté client qui envois des requêtes à l'API
-  Affichage du résultat 
![demo](https://user-images.githubusercontent.com/45512639/161614897-4db6b87a-c7e7-4ef7-9c36-add1afa52178.png)


### Exemple add-on result

https://user-images.githubusercontent.com/45512639/161617471-7c407306-c874-4313-95ec-744af9604912.mov

### Team member

- [Tatiana DEHON](https://www.linkedin.com/in/tatiana-dehon-62ba43198/)
- [Alexandre BREUIL](https://www.linkedin.com/in/alexandre-breuil-2003/)
- [Louis GOBERT](https://www.linkedin.com/in/louis-gobert-889a2314b/)
