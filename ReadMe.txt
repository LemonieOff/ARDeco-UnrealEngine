Projet Unreal Engine 5 - Application de Placement de Meubles en Réalité Augmentée

Ce Readme contient des informations essentielles pour les membres de l'équipe travaillant sur ce projet Unreal Engine 5. Veuillez suivre ces directives pour maintenir la cohérence et la collaboration efficace.

---------------------

Configuration requise

Unreal Engine 5 (version 5.4.1)
Matériel de développement AR compatible
Java : https://www.oracle.com/fr-fr/java/technologies/downloads/
	Java 17 
Android Studio : https://developer.android.com/studio
	Android 13 (Tiramisu) API level 33
	Android SDK Build Tools
	  - 33.0.1
	Android NDK Build Tools
 	  - 25.1.8937393
	Android SDK Command-line tools (tous les prendre pour être sur)
	Cmake 
	  - 3.22.1
	  - 3.10.2.4988404
	Android Emulator
	Android Emulator hypervisordriver (installer)
	Android SDK Platform-tools
	Google USB Driver
[Liste d'autres dépendances ici, le cas échéant]

----------------

Structure du projet

Le projet est structuré de la manière suivante :

Content: Contient tous les actifs du jeu, y compris les modèles 3D, les textures, les matériaux, les animations, etc.
Blueprints: Contient les Blueprints utilisés pour la logique du jeu.
Source: Les fichiers source du projet (le cas échéant).
Documentation: Documents, captures d'écran et autres informations pertinentes.
Builds: Les builds de l'application pour le déploiement sur les appareils mobiles (iOS, Android, etc.).
Autres dossiers pertinents, le cas échéant

----------------

Normes de nommage

Actifs UE5 : Utilisez le nommage standard d'Unreal Engine 5 pour les actifs (PascalCase pour les classes, snake_case pour les variables).
Fichiers et dossiers : Utilisez des noms descriptifs et en minuscules avec des underscores (par exemple, my_asset.uasset, my_blueprint.uasset).
Commentaires : Utilisez des commentaires clairs et concis pour expliquer la logique complexe ou les solutions techniques.

----------------

Flux de travail de développement

Créez une branche de fonctionnalité à partir de la branche develop.
Travaillez sur votre fonctionnalité ou correction de bug.
Assurez-vous de maintenir des commits atomiques et des messages de commit informatifs.
Lorsque votre travail est prêt, soumettez une demande d'extraction vers develop.
Les membres de l'équipe examineront et fusionneront la demande d'extraction après validation.

----------------

Gestion de projet

L'outil de gestion de projet est Github Project pour suivre les tâches et les attribuer aux membres de l'équipe.
Assurez-vous de tenir des réunions régulières pour discuter de l'état du projet et des prochaines étapes.
Documentation
Documentez tout code complexe ou non évident.
Incluez des captures d'écran ou des vidéos de l'application en action dans le dossier Documentation.

----------------

Ressources supplémentaires

Lien vers la documentation Unreal Engine 5
[Lien vers la documentation ARCore/ARKit, le cas échéant]
[Liste d'autres ressources utiles]

----------------

Contact
Pour toute question ou préoccupation, veuillez contacter Evan Blachier.
