# CS509: Post Graduation Software Lab

## 👤 Student Information
* **Name:** Muppuri Malyadri Lakshmi Narasimha
* **ID:** 2026AIM1014
* **Course:** CS509 (Post Graduation Software Laboratory)
* **Language Platform:** C++ (ISO C++26 Standard)
* **Development Environment:** Visual Studio Code (VS Code)

---

## 📂 Project Directory Structure
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
g++ -std=c++26 common_wrapper/wrapper.cpp -o program
```

### 2. Execution
Run the compiled executable application directly from your main terminal:
```bash
./program
```
*(On standard native Windows Command Prompt environments, execute via `program.exe`)*

---

## 📄 Test File Format Specifications
Every test module configuration file situated inside the `tests/` directory represents exactly one test instance matching the structural input schema layout parsed sequentially by `std::cin`:

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
The dynamic complexity results tracked down to isolated algorithmic block executions (excluding OS compilation metrics and basic file I/O streams) are structured below:

| Assignment Code | Evaluated Method / Strategy | Target Input File | Matrix1  | Matrix 2 | Output  | Measured Algorithm Complexity Runtime (ms) |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Assignment 01** | Simple Nested Loops | `test_01.txt` | $2 \times 3$ | $3 \times 2$ | $2 \times 2$ |   **0.004 ms**  |
| **Assignment 01** | Simple Nested Loops | `test_02.txt` | $3 \times 3$ | $3 \times 3$ | $3 \times 3$ | **0.003 ms**    |
| **Assignment 01** | Simple Nested Loops | `test_03.txt` | $4 \times 4$ | $4 \times 4$ | $4 \times 4$ | **0.006 ms**    |
| **Assignment 01** | Simple Nested Loops | `test_04.txt` | $5 \times 5$ | $5 \times 5$ | $5 \times 5$ |**0.008 ms**     |
| **Assignment 01** | Simple Nested Loops | `test_05.txt` | $6 \times 6$ | $6 \times 6$ | $6 \times 6$ | **0.008 ms**    |
| **Assignment 01** | Simple Nested Loops | `test_06.txt` | $7 \times 7$ | $7 \times 7$ | $7 \times 7$ | **0.015 ms**    |
