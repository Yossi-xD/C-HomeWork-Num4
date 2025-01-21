# 🦄 **Mythical Tamagotchi Royale** 🐉

Welcome to the **final** specifications for your Tamagotchi-like simulator. You **must** follow every detail exactly as described here—**no** personal flair or changes. This will ensure consistency across all submissions.

---

## **Project Structure**

You will create:

1. **Abstract Class**: `MagicalPet`  
2. **Two Derived Classes**: `DragonGotchi` and `PhoenixGotchi`  
3. **Custom Exception**: `MagicalException`  
4. **A Menu-Driven** `Main.cpp`  
5. **A File I/O Class**: `ReadWriteToFile` (with provided implementation)  
6. **Exactly 6 Pet Actions** in total (Feed, Play, Heal, Train, Show Status, Quit) plus 2 file operations (Save, Load).

All code must use **`char*`/`char[]`** or basic C++ types for string-like needs—no `std::string`. No `std::vector`.

---

### 1. **Abstract Class: `MagicalPet`**

Create `MagicalPet.hpp` with:
- Pure virtual methods:  
  - `feed(int)`  
  - `play()`  
  - `heal()`  
  - `train()`  
  - `showStatus()`

Each derived class must implement **exactly** the logic for feeding, playing, healing, training, and status printing specified below.

---

### 2. **Derived Classes** 

#### **2.1. DragonGotchi**  
- `hunger = 0` at start, `happiness = 10` at start  
- **feed(int)**  
  - If `<0`: throw `"Error: Negative feed amount!"`  
  - If `>10`: throw `"Error: Feed amount too high for Dragon!"`  
  - Else: `hunger += amount` (cap at 20), `happiness += amount/2` (cap at 50)  
- **play()**  
  - If `hunger >= 15`: throw `"Error: Dragon is too hungry to play!"`  
  - Else: `hunger -= 5` (not below 0), `happiness += 3` (cap at 50)  
- **heal()**  
  - `hunger -= 3` (not below 0)  
  - `happiness += 5` (cap at 50)  
- **train()**  
  - `hunger += 2` (cap at 20)  
  - `happiness -= 2` (not below 0)  
- **showStatus()**  
  - Print one line:  
    ```
    === DragonGotchi Status === Hunger: [hunger] Happiness: [happiness]
    ```

#### **2.2. PhoenixGotchi**  
- `hunger = 5` at start, `happiness = 5` at start  
- **feed(int)**  
  - If `<0`: throw `"Error: Negative feed amount!"`  
  - If `>10`: throw `"Error: Feed amount too high for Phoenix!"`  
  - Else: `hunger += amount` (cap at 30), `happiness += amount/3` (cap at 40)  
- **play()**  
  - If `hunger >= 20`: throw `"Error: Phoenix is too hungry to play!"`  
  - Else: `hunger -= 3` (not below 0), `happiness += 5` (cap at 40)  
- **heal()**  
  - `hunger -= 2` (not below 0)  
  - `happiness += 8` (cap at 40)  
- **train()**  
  - `hunger += 4` (cap at 30)  
  - `happiness -= 1` (not below 0)  
- **showStatus()**  
  - Print one line:  
    ```
    === PhoenixGotchi Status === Hunger: [hunger] Happiness: [happiness]
    ```

---

### 3. **Custom Exception: `MagicalException`**

- Must inherit `std::exception`.
- `what()` returns the **exact** error messages as needed:
  - `"Error: Negative feed amount!"`
  - `"Error: Feed amount too high for Dragon!"`
  - `"Error: Feed amount too high for Phoenix!"`
  - `"Error: Dragon is too hungry to play!"`
  - `"Error: Phoenix is too hungry to play!"`
  - (Or additional messages if needed.)

---

### 4. **File I/O with `ReadWriteToFile`**

You will **save** and **load** both pets’ states (`hunger`/`happiness`) to a file named `petsData.txt`.  
- **saveData(...)**: write two lines (Dragon first, Phoenix second).  
- **loadData(...)**: read those lines back and update each pet.

We provide fully implemented `ReadWriteToFile.hpp` and `ReadWriteToFile.cpp`.

---

### 5. **Menu** in `Main.cpp`

You must provide these **8** options:

1. Feed a pet  
2. Play with a pet  
3. Heal a pet  
4. Train a pet  
5. Show status of all pets  
6. Save data to file  
7. Load data from file  
8. Quit  

**Read `int choice`** from user. For each pet action, ask which pet (0 for Dragon, 1 for Phoenix). Handle out-of-range index. Catch exceptions.

---

## **Checklist**

1. **Abstract Class** `MagicalPet` with 5 pure virtual methods.  
2. **Two Derived Classes**: `DragonGotchi` & `PhoenixGotchi` with the exact logic.  
3. **Custom Exception**: `MagicalException`.  
4. **File I/O**: `ReadWriteToFile` saving/loading from `petsData.txt`.  
5. **Main Menu**: 8 items, no changes to required texts, use `int choice`, catch exceptions.

Implement all exactly as stated! Good luck and happy coding!
