FROM condaforge/mambaforge

LABEL maintainer.name="Matthias Hölzl"
LABEL maintainer.email="tc@xantira.com"

ARG ROOT_VERSION=6.26.00
ARG PYTHON_VERSION=3.9

RUN apt-get update && apt-get install --yes libglu1-mesa-dev freeglut3-dev mesa-common-dev && apt-get clean && \
    conda config --set allow_softlinks false && \
    conda config --set always_copy true && \
    mamba install --yes --quiet -c anaconda python=$PYTHON_VERSION root=$ROOT_VERSION jupytext ipyparallel metakernel zeromq && \
    conda clean --yes --all --force-pkgs-dirs

COPY entry_point.sh /
RUN chmod +x /entry_point.sh

RUN useradd --create-home --home-dir /userhome --shell /bin/bash docker-user
ENV HOME /userhome
USER docker-user
WORKDIR /userhome

EXPOSE 8888
ENTRYPOINT ["/entry_point.sh"]
# CMD ["root", "--notebook", "--ip='*'", "--allow_remote_access=True", \
#     "--password='argon2:$argon2id$v=19$m=10240,t=10,p=8$g+hKGGKL15g3h+BFScla/Q$ba0AUpijYzQu3o41cQhABaASKp3FOjAoHIArUjIY/b0'", \
#     "--password_required=True"]
CMD ["root", "--notebook", "--ip='*'"]
