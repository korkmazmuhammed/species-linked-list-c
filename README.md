
# Species Linked List Manager in C

This project implements a menu-driven system to collect, manage, sort, modify, and delete biological species information using a singly linked list in C.

## Project Overview

The user can store information about species, including **class, order, family, genus, and species**. All entries are dynamically allocated as nodes in a linked list. The system supports adding new species, sorting the list by any attribute, printing all entries, modifying details, deleting any species, and cleanly exiting.

Developed as part of **GTU CSE102 Assignment 13**.

**Author:** Muhammed Korkmaz  
**Student ID:** 220104004043  
**University:** Gebze Technical University

---

## Features

- **Add Species:** Enter species data and append it to the linked list.
- **Sort:** Sort the list by class, order, family, genus, or species (user selection).
- **Print:** Display all species and their hierarchical info.
- **Delete:** Remove any species entry by species name.
- **Modify:** Update all data for a species (found by its name).
- **Menu System:** Intuitive, easy to follow, and repeatable until exit.

---

## Menu Options

WHAT DO YOU WANT TO DO
1: ADD INFORMATION
2: SORT BY SELECTED CRITERIA
3: PRINT INFORMATION
4: DELETE INFORMATRION
5: MODIFY INFORMATRION
6: EXIT

---

## How to Compile and Run

```bash
gcc --ansi Muhammed_Korkmaz.c -o species_manager
./species_manager
```

---

## Example Usage

Class: Mammalia
Order: Carnivora
Family: Felidae
Genus: Panthera
Species: leo

Class: Aves
Order: Passeriformes
Family: Corvidae
Genus: Corvus
Species: corax

# Print Information
Class: Mammalia
Order: Carnivora
Family: Felidae
Genus: Panthera
Species: leo

Class: Aves
Order: Passeriformes
Family: Corvidae
Genus: Corvus
Species: corax

---

## Code Structure and Functions

- `Inf struct`: Holds pointers for class, order, family, genus, species, and the next node.
- `inf_create()`: Allocates and initializes new species nodes.
- `find_last()`: Finds the last node in the list.
- `print_inf()`: Prints all species in the list.
- `find_prev()`: Finds the previous node of a given entry.
- `sort_by_thing()`: Sorts the list by the chosen attribute.
- `determineChoice()`: Maps user input (class/order/...) to sorting index.
- `modify()`: Finds a species and updates its info with new user input.
- `delete()`: Removes a species node from the list by species name.

---

## Notes

- **No libraries** except `<stdio.h>` and `<string.h>` are used.
- **Dynamic memory management**: All allocations are freed on deletion.
- **Output format** strictly follows the assignment requirements.
- For demo and results, see the assignment report PDF and video:  
  [YouTube Demo](https://youtu.be/Lo8Ha-aFNuw)

---

## Files

- `Muhammed_Korkmaz.c` — Main program
- `Muhammed_korkmaz.pdf` — Report (with output screenshots & YouTube link)
- `CSE 102 Assignment 13.pdf` — Assignment instructions

---

## Author

**Muhammed Korkmaz**  
Gebze Technical University  
Student ID: 220104004043
