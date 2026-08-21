# CS509: Post Graduation Software Lab

## 👤 Student Information
* **Name:** Muppuri Malyadri Lakshmi Narasimha
* **ID:** 2026AIM1014
* **Course:** CS509 (Post Graduation Software Laboratory)
* **Language Platform:** C++ (ISO C++26 Standard)
* **Development Environment:** Visual Studio Code (VS Code)

---

## 📂 Assignment Directory Structure
The repository is organized into distinct, decoupled structural layers separating the automated test runner, algorithm drivers, data parsing modules, and individual algorithm test cases.

```text
Master/
├── common_wrapper/
│   └── wrapper.cpp          # Automated test suite controller & benchmark runner
├── driver/
│   └── [algorithm].cpp      # Implementation files hosting core optimization algorithms
├── src/
│   └── [module].cpp         # Source scripts passing and managing data feeding driver methods
├── tests/
│   ├── tests_bellman/         
│   │   ├── test_10.txt
│   │   ├── test_100.txt
│   │   └── ...
│   └── tests_floyd/          
│       ├── test_10.txt          
│       ├── test_100.txt
│       └── ...
└── README.md                # Project documentation and comprehensive execution matrix
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
*(On standard native Windows Command Prompt environments, execute via `assignment.exe`)*

---

## 📄 Test File Format Specifications

### 1. Bellman-Ford Input Format
```text
<number_of_vertices>
<number_of_edges>
<0_for_Undirected_OR_1_for_Directed>
<source_0> <destination_0> <weight_0>
<source_1> <destination_1> <weight_1>
...
<sourceE_1> <destinationE_1> <weightE_1>
```

#### Sample Bellman-Ford Input (`test_01.txt`)
```text
4
4
0
0 1 4
0 2 5
1 3 3
2 3 -2
```

### 2. Floyd-Warshall Input Format
```text
<number_of_vertices>
<adjacency_matrix_row_0_elements_separated_by_spaces>
<adjacency_matrix_row_1_elements_separated_by_spaces>
...
<adjacency_matrix_row_v-1_elements_separated_by_spaces>
```

#### Sample Floyd-Warshall Input (`test_01.txt`)
```text
3
0 4 11
6 0 2
3 1000000000 0
```

---

## 📊 Algorithmic Performance Evaluation Matrix

### Bellman-Ford Optimization Benchmarks

| Algorithm | Test File | Vertices | Edges | Negative Cycle | Time | Status |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Bellman-Ford** | `test_10.txt` | 10 | 20 | No | 0.321 ms | Pass |
| **Bellman-Ford** | `test_100.txt` | 100 | 300 | No | 0.923 ms | Pass |
| **Bellman-Ford** | `test_10000.txt` | 10000 | 30000 | No | 6983.21 ms | Pass |
| **Bellman-Ford** | `test_50000.txt` | 50000 | 150000 | No | 15023.64 ms | Pass |
| **Bellman-Ford** | `test_100000.txt` | 100000 | 300000 | No | 994561.3 ms | Pass |

### Floyd-Warshall Optimization Benchmarks

| Algorithm | Test File | Vertices | Negative Cycle | Time | Status |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Floyd-Warshall** | `test_10.txt` | 10 | No | 0.056 ms | Pass |
| **Floyd-Warshall** | `test_100.txt` | 100 | No | 3.987 ms | Pass |
| **Floyd-Warshall** | `test_500.txt` | 100 | No | 26.542 ms | Pass |
| **Floyd-Warshall** | `test_1000.txt` | 1000 | No | 23416.2 ms | Pass |
| **Floyd-Warshall** | `test_2000.txt` | 2000 | No | 338390.39 ms | Pass |

---

## 🛠️ About common_wrapper Component
The automated pipeline orchestrates performance testing across independent module layers:

```text
                               ------------------------

                               | Flow of the Program  |
                               ------------------------
                                          |
                              ---------------------------------------

                              |   running wrapper.cpp               |
                              |  creating assignment.exe            |
                              ---------------------------------------
                                         |
                                         |-----> Bellman-Ford Module (CSR-driven shortest path validation)
                                         |-----> Floyd-Warshall Module (Dense matrix parsing and evaluation)
```
