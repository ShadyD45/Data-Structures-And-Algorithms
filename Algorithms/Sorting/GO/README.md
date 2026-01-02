# Sorting Algorithms in Go

A small Go program to run classic **sorting algorithms** on a randomly
generated integer array.
Built for learning Go and practicing data structures.

------------------------------------------------------------------------

## ▶️ Usage

Run from the directory containing the files:

``` bash
go run . <sort-algo> <array-size>
```

### Examples

``` bash
go run . quicksort 10
go run . mergesort 20
```

> Use `go run .` so Go compiles all sorting files together.

------------------------------------------------------------------------

## 🔀 Supported Algorithms

-   `quicksort`
-   `mergesort`

(Algorithm names are case-insensitive)

------------------------------------------------------------------------

## 📂 Structure

    .
    ├── sort.go        # CLI entry point
    ├── quicksort.go   # Quick sort implementation
    └── mergesort.go   # Merge sort implementation

All files are part of `package main`.

------------------------------------------------------------------------

## 📊 What It Does

-   Validates command-line arguments\
-   Generates a random integer array\
-   Runs the selected sorting algorithm\
-   Prints the array before and after sorting

------------------------------------------------------------------------

## 🎯 Purpose

-   Learn Go basics
-   Implement and test sorting algorithms
-   Understand Go's package-based compilation model
