Projet de C++/QT - CIR2 2018
Auteur: G. Leroy-Ferrec


Les sources à compiler se trouvent dans le dossier src/build.
Exécuter 'make build' depuis la racine du projet permet de compiler le projet.

Pour que ça compile :
-Vérifiez que vous avez ajouté QT += core widgets à la fin de build.pro aprés avoir exécuté qmake
-Ajoutez -std=c++14 à la fin de la ligne CXXFLAGS dans le Makefile aprés chaque exécution de qmake ! IMPORTANT !

Il est possible que l'interface ne s'affiche pas correctement sur certains environnements. Il suffit alors de lancer
l'application avec un terminal utilisant aussi QT. "Cool Retro Term" fonctionne bien pour cela.
Par exemple sous Unity, lancer l'application depuis l'explorateur de fichiers causera des artéfacts au niveau de l'
interface.
