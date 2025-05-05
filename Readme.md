[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/SQy14o9b)
# Project Genie Info

  1. [Prerequisites](#1-prerequisites)
  2. [Clone project](#2-clone-project)
  3. [Install librairies](#3-install-librairies)
  4. [Install](#4-install)
  5. [Let's start working](#5-lets-start-working)

## 1 Prerequisites

### 1-1 Install required extensions
- Go to "Extensions" view (CTRL + Shift + X)
- Use search bar to find and install GitHub Pull Requests and Issues
 <img src="https://user-images.githubusercontent.com/16139930/168248657-8267ab92-1e1e-4642-9406-2f02fcc6a6ec.PNG" width="500px"/>
- Use search bar to find and install CMake and CMake tool support for VS Code

<img src="https://user-images.githubusercontent.com/16139930/168254129-b86fe4e7-2c5f-4700-a503-41de653d0199.PNG" width="400px" />  <img src="https://user-images.githubusercontent.com/16139930/168254203-dff13fb0-8b27-45ba-889c-482826f0ae47.PNG" width="400px" />





### 1-2 Connect your GitHub Account
- Go to "GitHub" view
- Click on "Sign in"

 <img src="https://user-images.githubusercontent.com/16139930/168287171-6991bcf8-392f-46ee-8f3a-4c9b7c6cf46c.png" width="150" />

- Allow GitHub Pull Requests and Issues extension

<img src="https://user-images.githubusercontent.com/16139930/168287186-2d974838-f3ee-4db8-a9cb-ffdfec8841a0.png" width="500px" />

- In browser, click on "choisir une application", then "ouvrir le lien"

![github_signin-3](https://user-images.githubusercontent.com/16139930/168287190-3e270d13-c791-475f-881e-ba0f690580d0.png)
![github_signin-4](https://user-images.githubusercontent.com/16139930/168287902-ea2c1f46-ce9b-410d-9724-614188ecc848.png)

- Click on "Open" in the next pop-up

 ![github_signin-5](https://user-images.githubusercontent.com/16139930/168288528-be08caad-12e9-45a0-8640-450214ae2b9c.png)

- In VS Code, click on "yes" button in the bottom right pop-up

![github_signin-6](https://user-images.githubusercontent.com/16139930/168288999-7552057a-a770-46d2-aff7-5772abbc0488.png)

- If you see "You are signed in now and can close this page." in your browser, you have successfully connected your GitHub account to VS Code.

in the terminal (ctrl + j) check that your git configuration has the correct name and email address (either your estia or the email address in https://github.com/settings/emails) 

```
$ git config user.name
dhmmasson
$ git config user.email
5263585+dhmmasson@users.noreply.github.com
```

If you want to update your email : 
```
$ git config user.email 5263585+dhmmasson@users.noreply.github.com
```


## 2 Clone project
- Open command palette (CTRL + SHIFT + P)
- Type "clone" and select "GIT: clone"
- Select "Clone from Github"
- Select "Estia-1a/pgi-2023-TeamName" project
- Select a location for the project
WARNING: No accents in your folder names! Otherwise, your project will not compile.
- Select "open" to: Would you like to open the cloned repository?
- Select "yes" to: Do you trust the authors?

## 3 Install librairies
- Go see the latest release https://github.com/Estia-1a/projetGenieInfo_public/releases (latest = v2.0.1 in June 2022), then:

**estia-image**
- Download the `estia-image` zip file correponding to your setup 
- (e.g., VS Code, Windows 10, with mingw 64 bits: [estia-image-v2.0.1-win10-mingw64](https://github.com/Estia-1a/projetGenieInfo_public/releases/download/v2.0.1/estia-image-v2.0.1-win10-mingw64.zip))
- Unzip the file
- Move the `estia-image/` folder in your project (near `src/`)

**getopt**
- Download the `getopt` zip file correponding to your setup (e.g., VS Code, Windows 10, with mingw 64 bits: [getopt-v2.0.1-win10-mingw64](https://github.com/Estia-1a/projetGenieInfo_public/releases/download/v2.0.1/getopt-v2.0.1-win10-mingw64.zip))
- Unzip the file
- Move the `getopt/` folder in your project (near `src/` and `estia-image/`)

the final structure should look exactly like that
>
> - .github
> - .vscode
> - estia-image
>   - include
>     - estia-image.h
>   - lib
>     - libestia-image.a
> - getopt
>   - include
>     - getopt.h
>   - lib
>     - libgetopt.a
> - images
> - src

## 4 Install
To install project you can either:
- use VS Code terminal and follow [Install in VS Code command line](#3-1-install-in-vs-code-command-line), or
- use VS Code CMAKE extension interface and follow [Install with VS Code CMAKE extension interface](#3-2-install-with-vs-code-cmake-extension-interface)

## 4-1 Install in VS Code command line
- cmake -B build
- cmake --build build
- cmake --install build
- freud.exe -f images/input/image.jpeg -c helloworld

## 4-2 Install with VS Code CMAKE extension interface
- If it doesn't start automatically: Open command palette (CTRL + SHIFT + P) and type CMake and choose : "CMake: Configure"
- Choose : GCC 4.6.0 [...]
- Build your project: click on "Build" button of the bottom blue bar (see bellow)

<img src="https://user-images.githubusercontent.com/16139930/171380204-6b37b499-0878-4a2d-ac0e-2b320faeed09.PNG" width="500px" />

- You must have a build folder now
- Install your project: 
  * Click on [all]
  * <img src="https://user-images.githubusercontent.com/16139930/171380432-96d768fe-ca9f-4c99-bac1-3811f3caacfe.PNG" width="500px" />
  * Choose install
  * Click on "Build" button of the bottom blue bar

- Run your code:

<img src="https://user-images.githubusercontent.com/16139930/168266156-eaed4cd2-0fe7-4bed-81d6-afd3b7485dee.png" width="500px" />

## 5. Importing the features to be implemented

From the github page of your project, one member of the team click on the menu Actions. Then on the left navigation select "Import issues from template". Finally click on the right on the button run workflow, and run the workflow on the main branch. 

<img width="1475" alt="Screen Shot 2023-06-07 at 10 39 28" src="https://github.com/Estia-1a/projetGenieInfo_public/assets/5263585/edd26d4c-af10-4d8c-8e2d-1ff811e0c6b3">

This will create issues (it may take some times). Each issue is related to a task you have to do in this project. 

## 6 Let's start working

Now, refer to the [wiki](https://github.com/Estia-1a/projetGenieInfo_public/wiki/How-to-start-working) to start working !

#### Tutorial
- [ ] Dimension https://github.com/Estia-1a/projetGenieInfo_template/issues/3
- [ ] Color of the first pixel https://github.com/Estia-1a/projetGenieInfo_template/issues/4
- [ ] Color of the 10th pixel https://github.com/Estia-1a/projetGenieInfo_template/issues/5
- [ ] Color of the first pixel on the second line https://github.com/Estia-1a/projetGenieInfo_template/issues/6
- [ ] RGB pixel, get and print functions https://github.com/Estia-1a/projetGenieInfo_template/issues/7
