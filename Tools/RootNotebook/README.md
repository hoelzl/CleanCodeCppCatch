# Docker file for C++ Notebooks

This directory contains files to build a docker image that runs a ROOT C++
kernel inside a docker notebook.

It is based on (this
example)[https://github.com/root-project/root-docker/tree/master/conda] from the
ROOT project.

## Building the image

To build the container run

```
$ docker build -t <hub-user>/root-notebook .
```

Run the container using 

```
$ docker run --name root-notebook -it  -v D:\\MyDir:/userhome/notebooks root-notebook
```

(Replace `D:\\MyDir` with the path to the notebook folder you want to use.)

After stopping the container, restart it with

```
$ docker start root-notebook
```
