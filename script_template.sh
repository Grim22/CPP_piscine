#!/bin/bash

export Class=${1^}
export Header=${1^^}

envsubst < Template.hpp > ${1^}.hpp
envsubst < Template.cpp > ${1^}.cpp