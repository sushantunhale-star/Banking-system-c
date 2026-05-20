# Banking System (C)

A simple file-based banking management system written in **C**. It supports creating accounts, viewing saved accounts, depositing money, and withdrawing money.

> Data is persisted in a binary file named **`accounts.dat`** in the project directory.

---

## Features

- **Create account**
  - Account number, customer name, and initial balance
  - Stored in `accounts.dat`
- **Display accounts**
  - Reads and prints all accounts from `accounts.dat`
- **Deposit money**
  - Finds account by account number
  - Updates balance and writes back to the same binary file
- **Withdraw money**
  - Checks sufficient balance before updating
- **Menu-driven program**
  - Repeats until you choose Exit

---

## Project Structure

- `main.c` — Main program and banking functions
- `accounts.dat` — Binary storage for account records (created/updated automatically)

---

## How It Works

Each account is stored as a fixed-size struct:

- `name[50]`
- `acc_no` (int)
- `balance` (float)

Operations like deposit/withdraw work by:

1. Opening `accounts.dat` in read/write mode (`rb+`)
2. Scanning records using `fread`
3. When the target account is found:
   - Update balance
   - Seek back to the record position
   - Overwrite using `fwrite`

---

## Build & Run

### Using GCC (MinGW/MSYS2)

Compile:

```bash
gcc main.c -o main.exe
```

Run:

```bash
./main.exe
```

> If your shell requires it on Windows PowerShell, you may need:
>
> ```powershell
> .\main.exe
> ```

---

## Usage

When you run the program, you’ll see a menu:

1. **Create Account**
2. **Display Account**
3. **Deposit Money**
4. **Withdraw Money**
5. **Exit**

Enter the account number and the amount when prompted.

---

## Notes

- This project stores data using a binary file and does not implement advanced safety checks like duplicate account number prevention.
- Balances and amounts are handled using `float`.

---

## License

Add your license information here (e.g., MIT).
