# clientServeur
Projet Système D'Exploitation


[![Evengue Tanga|Dominique Emilie](https://worldsbestbikestickers.com/wp-content/uploads/2014/10/Powered_By_Me_Re_4c9c0793985d8.png)](https://github.com/dominique-17/clientServeur.git)

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)


La différence entre un projet et un TD ou TP est que vous êtes beaucoup moins guidés, volontairement, vous n'avez pas eu de cours ou d'exemple de code afin que vous puissiez chercher par vous-même les solutions aux problèmes rencontrés.

En plus d'un répertoire git contenant vos codes sources et la marche à suivre pour installer et lancer votre travail vous devrez fournir un rapport indiquant votre démarche, les solutions que vous avez choisies pour répondre à vos problématiques.



## Caracteristiques

- Serveur de traitement des requetes
- Client emetteur de requetes vers le serveur

## Points Traitees
- Lister tous les fichiers present dans un dossier
- lister un fichier en particulier dans un fichier
- Supprimer tous les fichier dans un dossier

Le projet a ete developper en language C en utilisant un protocole appele [SOCKET][df1]. 
on peut le traduire par « [connecteur réseau][df1] » ou « [interface de connexion][df1] »
Il lui sera ainsi par exemple aisé d’établir une session [TCP][df1], puis de recevoir et d’expédier des données grâce à elle. Cela simplifie sa tâche car cette couche logicielle, de laquelle il requiert des services en appelant des fonctions, masque le travail nécessaire de gestion du réseau, pris en charge par le système.

Developper par [Evengue Tanga|Dominique Emilie][df1]

> La notion de socket a été introduite dans les distributions de
> Berkeley (un fameux système de type UNIX, dont beaucoup de 
> distributions actuelles utilisent des morceaux de code), c’est la 
> raison pour laquelle on parle parfois de sockets BSD (Berkeley 
> Software Distribution).  The overriding design goal for Markdown's




## Librairies

Pour developper le projet, nous avons eu besoin de nombreuses librairie tant pour le client que pour le serveur. Nous avons donc utiliser:

- [<stdio.h>]      - en-tête de la bibliothèque standard du C.
- [<string.h>]     - gestion des chaines de caractere.
- [<sys/socket.h>] - ensemble normalisé de fonctions de communication.
- [<arpa/inet.h>]  - Fonctions de manipulation des adresses IP numériques (partie des sockets Berkeley).
- [<unistd.h>]     - constantes et types symboliques standard - Référence des définitions de base.
- [<dirent.h>]     - fonctions de manipulation des répertoires du système de fichiers.

Il est aussi a noter que mon projet est open soucrce et disponible sur GitHub dans un [public repository][dill].

## Installation

Vous devez tout d'abord cloner le projet [clientServeur](https://github.com/dominique-17/clientServeur.git) Toute contribution est ouverte.

Ouvrir un terminal en executant le raccourci clavier.
```sh
CTRL + ALT +T
```

puis cloner le projet
```sh
GIT CLONE https://github.com/dominique-17/clientServeur.git
```

ensuite  demarer le serveur en premier

```sh
cd clientServeur
gcc serveur.c -o serveur
./serveur
```

ou 
```sh
cd clientServeur
gcc serveur.c -o serveur && ./serveur
```

une fois le serveur demarer, vous aurez un message
> En attente de connection

Ouvrir un autre terminal en executant le raccourci clavier.
```sh
CTRL + ALT + T
```
ensuite  demarer le client en second

```sh
cd clientServeur
gcc client.c -o client
./client
```

ou 
```sh
cd clientServeur
gcc client.c -o client && ./client
```


## Developpement

Vous souhaiter faire evoluer le code? Super!

le projet est ouvert a tout le monde.

il te suffit de respcter les regles suivantes:

Clone du projet de la branche [main]:

```sh
GIT CLONE https://github.com/dominique-17/clientServeur.git
```

Creer une branche DEV_[XXXXXX][dill] ou [XXXXXX][dill] represente l'increment de la branche dev la plus recement cree:

```sh
git checkout -b dev_000001 
[Si aucune branche dev n existe]
```

(✨Optionnel si tu es sure de toi✨)verifie ta branche courante:
```sh
git branch
```

tu peux effectuer tes modifications sur cette branche avec des commits explicatif afin de pouvoir les integrer a la main

## License

Pas de licence pour le moment

**Libre de tout usage**

[//]: # (These are reference links used in the body of this note and get stripped out when the markdown processor does its job. There is no need to format nicely because it shouldn't be seen. Thanks SO - http://stackoverflow.com/questions/4823468/store-comments-in-markdown-syntax)

   [dill]: <https://github.com/dominique-17>
   [git-repo-url]: <https://github.com/dominique-17/clientServeur.git>
   [john gruber]: <#>
   [df1]: <http://daringfireball.net/projects/markdown/>
   [markdown-it]: <https://github.com/markdown-it/markdown-it>

