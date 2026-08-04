# CS509: Post Graduation Software Lab

## 👤 Student Information
* **Name:** Muppuri Malyadri Lakshmi Narasimha
* **ID:** 2026AIM1014
* **Course:** CS509 (Post Graduation Software Laboratory)
* **Language Platform:** C++ (ISO C++26 Standard)
* **Development Environment:** Visual Studio Code (VS Code)

---

## 📂 AssignmentDirectory Structure
The repository is organized into distinct, decoupled structural layers separating the automated test runner, algorithm drivers, data parsing modules, and individual test cases.

```text
Master/
├── common_wrapper/
│   └── wrapper.cpp          # Automated test suite controller & benchmark runner
├── driver/
│   └── [algorithm].cpp      # Implementation files hosting core optimization algorithms
├── src/
│   └── [module].cpp         # Source scripts passing and managing data feeding driver methods
├── tests/
│   ├── test_01.txt          # Sequential evaluation text matrices
│   ├── test_02.txt          
│   └── test_03.txt          
└── README.md                # Repository documentation and comprehensive execution matrix
```

---

## ⚙️ Compilation & Execution

To orchestrate and evaluate the performance of structural algorithms from a single terminal workspace, compile and invoke the global automation test wrapper:

### 1. Compilation
Build the test execution wrapper utilizing the updated modern compiler flags:
```bash
g++ common_wrapper/wrapper.cpp -o assignment
```

### 2. Execution
Run the compiled executable application directly from your main terminal:
```bash
./assignment
```
*(On standard native Windows Command Prompt environments, execute via `program.exe`)*

---

## 📄 Test File Format Specifications
Test cases storing in test_xx.txt format file

```text
[M_ROWS]                                         <- Number of Rows (Matrix 1)
[K_COLS]                                         <- Number of Columns (Matrix 1)
[K_ROWS_M2]                                      <- Number of Rows (Matrix 2) [Must equal K_COLS]
[N_COLS_M2]                                      <- Number of Columns (Matrix 2)
[Matrix 1 - Row 1 Elements separated by spaces]
[Matrix 1 - Row 2 Elements separated by spaces]
...
[Matrix 2 - Row 1 Elements separated by spaces]
[Matrix 2 - Row 2 Elements separated by spaces]
...
```

### Raw Sample Target Array Vector Input (`test_01.txt`)
```text
3
3
3
3
1 2 3
4 5 6
7 8 9
1 0 0
0 1 0
0 0 1
```

---

## 📊 Algorithmic Performance Evaluation Matrix
The comparison of the two programs simple 3 loops matrix multiplication and tilling method mulitplication.

| Assignment Code | Target Input File | Matrix1  | Matrix 2 | Output  | Simple Three Loops Time Complexity Runtime (ms) | Tilling Method |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Assignment 01**  | `test_01.txt`  | $2 \times 3$       | $3 \times 2$       | $2 \times 2$       | **0.002 ms**    |  **0.004 ms**    |  
| **Assignment 01**  | `test_02.txt`  | $3 \times 3$       | $3 \times 3$       | $3 \times 3$       | **0.003 ms**    |  **0.003 ms**    |
| **Assignment 01**  | `test_03.txt`  | $4 \times 4$       | $4 \times 4$       | $4 \times 4$       | **0.006 ms**    |  **0.009 ms**    |
| **Assignment 01**  | `test_04.txt`  | $5 \times 5$       | $5 \times 5$       | $5 \times 5$       | **0.010 ms**    |  **0.014 ms**    |
| **Assignment 01**  | `test_05.txt`  | $6 \times 6$       | $6 \times 6$       | $6 \times 6$       | **0.008 ms**    |  **0.013 ms**    |
| **Assignment 01**  | `test_06.txt`  | $7 \times 7$       | $7 \times 7$       | $7 \times 7$       | **0.012 ms**    |  **0.009 ms**    |
| **Assignment 01**  | `test_07.txt`  | $100 \times 100$   | $100 \times 100$   | $100 \times 100$   | **25.144 ms**   |  **15.823 ms**   |
| **Assignment 01**  | `test_08.txt`  | $200 \times 200$   | $200 \times 200$   | $200 \times 200$   | **194.492 ms**  |  **136.256 ms**  |
| **Assignment 01**  | `test_09.txt`  | $300 \times 300$   | $300 \times 300$   | $300 \times 300$   | **690.729 ms**  |  **461.695 ms**  |
| **Assignment 01**  | `test_10.txt`  | $400 \times 400$   | $400 \times 400$   | $400 \times 400$   | **1652.09 ms**  |  **1097.24 ms**  |
| **Assignment 01**  | `test_11.txt`  | $500 \times 500$   | $500 \times 500$   | $500 \times 500$   | **3137.36 ms**  |  **2251.06 ms**  |
| **Assignment 01**  | `test_12.txt`  | $1000 \times 1000$ | $1000 \times 1000$ | $1000 \times 1000$ | **25695.1 ms**  |  **16880 ms**    |
| **Assignment 01**  | `test_13.txt`  | $2000 \times 2000$ | $2000 \times 2000$ | $2000 \times 2000$ | **370444.0 ms** |  **167880 ms**   |

## 📊 Algorithmic Performance for 


| Assignment Code | Target Input File | vertices | edges | Runtime (ms)  |
| :--- | :--- | :--- | :--- | :--- | 
| **Assignment 01**  | `test_01.txt`  | 10       | 20       |  0.004 ms | 
| **Assignment 01**  | `test_02.txt`  | 100      | 200      |  0.032 ms | 
| **Assignment 01**  | `test_03.txt`  | 50000    |  100000  |  0.692 ms | 
| **Assignment 01**  | `test_04.txt`  |  10000   | 20000    |  5.60 ms  | 
| **Assignment 01**  | `test_05.txt`  |  100000  | 399996   |  11.791 ms| 


## About common-wrapper Folder
The wrapper folder is main folder which contains a wrapper.cpp for handling all assignment programs.

```text
                                                              ------------------------
                                                              | Flow of the Program  |
                                                              ------------------------
                                                                         |
                                                             ---------------------------------------
                                                             |   running wrapper.cpp               |
                                                             |  creating assignment.exe            |
                                                             --------------------------------------
                                                                        |
                                                                        |-----> Assingment_01--->|-----> 1. MatrixMultiplication simple loops
                                                                        |                        |-----> 2. Tilling Method
                                                                                                 |-----> 3. CSR Graph
```

