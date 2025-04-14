# Competitive Programming Solutions

This repository contains solutions to competitive programming problems from various **online judges** and  **competitions** . The solutions are organized into separate directories based on the **online judges** (e.g., UVA, HackerRank, Codeforces) and **competitions** (e.g., local or international programming competitions like Code Jam, ICPC, etc.).

Feel free to explore the solutions, contribute your own, or learn from others.

## Repository Structure

The repository is organized into two main categories:

### 1. **Competitions**

Solutions to problems from various programming competitions are stored here. Each competition has a separate directory, which is further organized by year and round.

Example:

```yaml
Competitions/
    ├── competition_a/
    │   ├── 2024/
    │   │   ├── round_1/
    │   │   ├── round_2/
    │   └── 2023/
    └── competition_b/
        ├── 2024/
        └── 2023/
```

### 2. **Online Judges**

Solutions to problems from various online judges are stored here. Each online judge has its own directory, with problem solutions organized by problem ID or name.

Example:
```yaml
Online Judges/
    ├── uva/
    │   ├── problem_1/
    │   ├── problem_2/
    ├── hackerrank/
    │   ├── problem_1/
    │   ├── problem_2/
    ├── codeforces/
    │   ├── problem_1/
    │   └── problem_2/
    └── leetcode/
        ├── problem_1/
        └── problem_2/

```

### 3. **Languages Supported**

Solutions are primarily provided in the following programming languages (but you can add more as needed):

* **C++**
* **Python**
* **Java**

## How to Contribute

We welcome contributions! If you have solutions to competitive programming problems from any online judge or competition, feel free to add them to the appropriate directory.

### Steps to Contribute:

1. **Fork** the repository.
2. **Clone** your forked repository to your local machine.
3. **Navigate** to the correct directory (either `competitions` or `online_judges`).
4. **Create a folder** for the problem or competition (if it doesn't already exist).
5. **Add your solution** in the appropriate language folder (e.g., `cpp`, `python`, `java`).
6. **Submit a pull request** with a description of the added solutions.

### Naming Conventions:

* **For Online Judges** : Use the format `problem_<ID>` (e.g., `problem_1001`, `two_sum`).
* **For Competitions** : Use the format `competition_<name>` and structure the rounds and years appropriately.
* **For Languages** : Store solutions in folders named after the language (e.g., `cpp`, `python`, `java`).

## How to Run the Solutions

Each solution is typically self-contained and should be executable on its own. Make sure you have the correct compiler or interpreter installed for the language you're working with:

* For **C++** solutions, ensure you have a C++ compiler (e.g., g++).
* For **Python** solutions, ensure you have Python 3.x installed.
* For **Java** solutions, ensure you have Java installed.

You can also use any online judge or IDE to test the code directly.

## Adding New Online Judges or Competitions

To add solutions for a new **online judge** or  **competition** , follow these steps:

1. **Create a new directory** under `online_judges` or `competitions`.
2. **Structure the directory** by year and round for competitions, or by problem ID for online judges.
3. **Add your solutions** and follow the naming conventions.

For example, if you want to add solutions from Codeforces:

```yaml
online_judges/
    ├── codeforces/
    │   ├── problem_1/
    │   ├── problem_2/
```


## Issues and Discussions

If you find any issues with the code or have suggestions for improvements, feel free to open an issue or create a discussion in the repository.

## License

This repository is open source and available under the [MIT License](#license).
