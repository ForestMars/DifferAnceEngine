# DifferAnce Engine

At a high level, DifferAnce Engine (hereafter, DAE) is a meta-learning framework for distinguishing between objects of any collection, in a highly efficient and scalable manner, with minimal oversight required but maximum configuration enabled.

An important design principle behind DAE is that classification inaccuracies arise from hidden assumptions that impact the target domain, and thus the minimization of such assumptions reduces classification error in a measurable way.


## Table of contents

  * [Overview](#differance-engine)
  * [How It Works](how-it-works)
  * [Build](#build)
  * [Install](#install)
      * [Requirements](#requirements)
  * [Deploy](#deploy)
  * [Run](#run)
  * [Example Domains](#example-domains)
  * [Release Notes](#release-notes)
      * [Known Issues](#known-issues)
  * [Contributing](#contributing)
    * [Feedback](#feedback)    
  * [License](#license)  
  * [Dicata](#dicata)


## How It Works

DifferAnce Engine has the following modes of operation:
* API: In this mode the API is running and can accept and requests supported in `API.domain`, which defines available classification domain commands.
* Train: Train a specified model with a particular set of hyperparameters.
* Learn: Iterate over dataset to find best hyperparameters for a given model or models.
* Predict: Run a model on a specified endpoint, or package trained model as a Docker image.  

Predict mode is essentially the same as API mode, with at least one domain running an optimized model.

The main intents behind DifferAnce Engine (besides building a framework that has the ability to "tell the difference between any 2 things") are firstly to create an API based solution for all the classification problems that otherwise require a great deal of repetitive and tedious coding. Secondly, to enable a highly configurable Auto-ML framework, giving fine grained control over searching a computationally huge search space, and finally to provide a stepping stone from Auto-ML based approaches to true Meta-learning. This is mainly acheived through integration with [Someta] Meta-learning framework.

Scalability of the computationally expensive parameter optimizations is not handled by DifferAnce Engine, but is offloaded to the Fast ML pipeline, which takes care of parallelizing the processes and auto-scaling as needed.

The pipe factory changes the convention of of naming things after their labels (ie.`make_pipeline`) in favour of naming them after the hash of their functors. This allows for their names to freely (and arbitrarily) change, while maintaining the integrity of the object itself that’s being passed.


## Install

To install, source the included conda environment file. That should be all you need to do for a fully running DifferAnce Engine environment.

### Notes on Requirements:
* Cython: DAE builds all modules as Cython extensions, located in `lib/ext`
* SWIG: There are a couple of libraries used that need a SWIG wrapper.


## Run

To run DAE from the command line the first argument will be the mode name you wish to run:
* **learn** - Learn the best hyperparameters for a given domain.
* **train** - Train a given model with a known set of hyperparameters.
* **predict** - Run a trained model to predict over a real time data stream.*
* **score** - Score model against a given dataset.
* **show** - Plot best hyperparameters visually.


## Example Domains

### Candidates

DifferAnce Engine has been successfully used as a resumé sorting system for machine learning engineering candidates. You can try it out for yourself: [Candidates](https://github.com/ForestMars/Candidates).

### Contract Analysis

Mainly intended as solution for sorting through very (VERY) large data lakes to classify voluminous quantities of documents, DifferAnce engine has also had some promising sucesses in distinguishing "good" contracts from "bad" and red flagging documents flowing through a workflow for review.

The forthcoming release will also include the experimental "album" mode, an extremely low training but highly robust model that has extremely modest computational requirements in comparision with other contract classification models.

### Sample Datasets

To get started with DiffEng, a well-known dataset with oneological data is included.

### Wikipedia

Finally, an experimental Wikipedia scraper is included in the `wikip/` sub-directory. (not built as wheel.) Using this tool you can download any data from Wikipedia to explore the capabilities of DifferAnce Engine.


## Release Notes

* Version 0.1

* real time prediction (`dae predict [MODEL_ID`] is inherited from Timecube auto-regressive framework. Classification data is not "real time" -in the sense it's not time series data- however DAE is able to handle extremely high workloads with extremely low latency.

### Known Issues

* [Cython 0.29.14 and Py38 generates warnings for tp_print](https://github.com/cython/cython/issues/3474)


## Roadmap

* Coda.to integration
* Someta integration

### Misc ToDo's

* Move setup.py out of `build/src` intp `build`
* Clean up domain logic & some residual hard coded constants


## License

DifferAnce Engine is released under the Apache Software License.


## Dictata

DifferAnce Engine is dedicated to Charles Babbage and Jacques Derrida, if that was not obvious.
