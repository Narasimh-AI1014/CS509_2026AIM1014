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
│   ├── tests_prims/         
│   │   ├── test_10.txt
│   │   ├── test_100.txt
│   │   └── ...
│   └── tests_kruskal/          
│       ├── test_10.txt          
│       ├── test_100.txt
│       └── ...
└── README.md                # Project documentation and setup guide
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

### Prim's & Kruskal's MST Input Format
The graph file is structured as an adjacency list containing the number of nodes, total edges, and node structural degrees:
```text
<number_of_vertices> <number_of_edges>
u0 degree neighbor1 weight1 neighbor2 weight2 ...
u1 degree neighbor1 weight1 neighbor2 weight2 ...
...
u(V-1) degree neighbor1 weight1 neighbor2 weight2 ...
```

#### Raw Sample Graph Input (`test_01.txt`)
```text
5 7
0 2 1 2 3 6 
1 4 0 2 2 3 3 8 4 5
2 2 1 3 4 7 
3 3 0 6 1 8 4 9
4 3 1 5 2 7 3 9
```

---

## 📊 Algorithmic Performance Evaluation Matrix

### MST Optimization Benchmarks

| Algorithm | Test File | V | E | Expwt | Kruskalwt | Primswt | Kruskal Time | Prims Time | Equal | Status |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **MST** | `test_10.txt` | 10 | 22 | 9 | 9 | 9 | 0.019 ms | 0.013 ms | Yes | Pass |
| **MST** | `test_100.txt` | 100 | 292 | 99 | 99 | 99 | 0.089 ms | 0.156 ms | Yes | Pass |
| **MST** | `test_10000.txt` | 10000 | 29992 | 9999 | 9999 | 9999 | 2.5166 ms | 15.092 ms | Yes | Pass |
| **MST** | `test_50000.txt` | 50000 | 149992 | 49999 | 49999 | 49999 | 17.8560 ms | 76.671 ms | Yes | Pass |
| **MST** | `test_100000.txt`| 100000| 299992 | 99999 | 99999 | 99999 | 33.8500 ms | 159.350 ms| Yes | Pass |

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
                                         |-----> Prim's Algorithm Module (Priority-queue driven extraction)
                                         |-----> Kruskal's Algorithm Module (Disjoint Set Union forest processing)
```

