cmake_minimum_required(VERSION 3.17)
project(ass1)

set(CMAKE_CXX_STANDARD 11)

add_executable(ass1 main.cpp
        Classifiable.h
        Iris.cpp Iris.h
        KnnClassifier.cpp KnnClassifier.h
        Reader.cpp Reader.h
        Classifier.h)