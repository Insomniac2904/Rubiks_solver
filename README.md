<h1 align="center" id="title">🎮 Rubik's Cube Solver</h1>

<p id="description">This is a Rubik's Cube solver that demonstrates the use of the IDA* algorithm to find the optimal solution of a valid randomly shuffled Rubik's Cube in under <b>11 seconds</b>. ⏳</p>

---

## ✨ Demonstration of the Solver in Action

Here is a demonstration of the solver applied to a Rubik's Cube shuffled <b>6 times</b>:

### ✅ **DFS Solver**

![DFS Solver](https://github.com/user-attachments/assets/4a92dca9-a4b3-4efd-9560-1b25dd395e32)

✅ The DFS solver with a max depth of 7 performs well but **does not always provide an optimal solution**.

---

### ✅ **IDDFS Solver**

![IDDFS Solver](https://github.com/user-attachments/assets/8bc42771-0c78-433e-bde9-aed03ac50cb8)

✅ The IDDFS solver **finds an optimal solution** in a time comparable to DFS.

---

### ✅ **IDA* Solver**

![IDA* Solver](https://github.com/user-attachments/assets/50236609-b803-4375-97ec-8ff4ae856cdc)

✅ The IDA* solver also provides **an optimal solution** within a similar time frame as DFS and IDDFS.

---

## ⚠️ **Note:**

- The Rubik's Cube is **shuffled randomly** before solving.
- There are cases where the **DFS solver fails** to find a solution within the allowed max depth.
- The IDDFS and IDA* algorithms consistently produce optimal results in **less than 11 seconds**. ⏳✨🎮

