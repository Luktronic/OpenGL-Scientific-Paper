<p align="center">
    <a href="https://www.opengl.org/" target="blank">
        <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/e9/Opengl-logo.svg/1920px-Opengl-logo.svg.png" height="150" alt="OpenGL"/>
    </a>
    <a>
        <img src="https://brandslogos.com/wp-content/uploads/images/large/c-logo.png" height="150" alt="C++"/>
    </a>
</p>

<p align="center">
    <img src="https://img.shields.io/github/directory-file-count/Luktronic/OpenGL-Scientific-Paper.svg" alt="File Count" />
    <img src="https://img.shields.io/github/repo-size/Luktronic/OpenGL-Scientific-Paper.svg" alt="Repo Size" />
    <img src="https://github.com/Luktronic/OpenGL-Scientific-Paper/actions/workflows/build.yml/badge.svg" alt="Thesis Build"/>
</p>

# OpenGL Scientific Paper

This repository contains a scientific paper about rendering with <a href="https://www.opengl.org/" target="blank">OpenGL</a>, C++ and <a href="https://www.glfw.org/" target="blank">GLFW</a>. The source code of the project is also included in the repository.

The paper was written in [Asciidoc](https://asciidoc.org/), using [this](https://github.com/Alwinator/thesis-template) template.

## Prerequisites

### Paper

- Docker

### Project

- Git
- Python (required for build)

**Coming soon**

## How to build

Firstly, clone this GitHub repository recursively:

```sh
> git clone --recursive https://github.com/Luktronic/OpenGL-Scientific-Paper.git
```

---

### Build Paper

See <a href="https://github.com/Alwinator/thesis-template#getting-started" target="blank">here</a>.

---

### Build Project

Make sure you have cloned all the **submodules**. If you have not cloned this repository recursively, you can use `git submodule update --init` to clone the submodules afterwards.

---

#### Windows

Open the terminal (Powershell or CMD) in the `/project/setup` directory. After that, run the `setup.bat` file

```sh
> .\setup.bat
```

**You have to run the script from the `/project/setup` subdirectory, otherwise it will not work!**  

The script should install the necessary Python modules, as well as Premake. It should also execute Premake and generate a Visual Studio 2022 project.  

You can then simply run or build the project in Visual Studio by opening the `OpenGLPaper.sln` file.

If you don't want to use Visual Studio, you can also build the project with `MsBuild`. Just type the following command into Powershell/CMD:

```sh
> msbuild .\OpenGLPaper.sln 
```

If you don't have `MsBuild` in your `PATH`, you will not be able to execute the `msbuild` command. If that is the case, add the following directory to your `PATH`:

```
[Your Visual Studio Installation]\Msbuild\Current\Bin
```

Now you should be able to run `msbuild` in the terminal.

After all of that, you will find an `OpenGLPaper.exe` executable in the `/project/bin` directory.
#### MacOS

Not tested yet - coming soon!

#### Linux

Not tested yet - coming soon!

## Disclaimer

Many parts of this project - especially the Premake build pipeline - are heavily inspired by [TheCherno's](https://www.youtube.com/c/TheChernoProject) [Hazel Engine](https://github.com/TheCherno/Hazel) project on [YouTube](https://www.youtube.com/playlist?list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT). I have taken some build scripts and modified them for my own use, so credits go to him and his amazing work!

I am also using [this](https://github.com/Alwinator/thesis-template) Asciidoc thesis template, so shoutouts to the creator [Alwinator](https://github.com/Alwinator)!
