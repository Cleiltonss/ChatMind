# ChatMind 🤖🧠

**ChatMind** is an interactive **C++ console-based chatbot** that simulates a natural conversation with the user. Built from scratch using only the C++ Standard Library, ChatMind supports:

- Predefined and randomized responses for casual interaction
- User-driven learning through a `teach` command (e.g., `teach pizza I love pizza too!`)
- Session-based memory to remember user information like **name**, **age**, **favorite food**, and **color**
- Logging of unknown or unrecognized inputs to allow future training
- A clean, modular project structure for maintainability and future expansion

Unlike AI-driven bots, **ChatMind** relies on simple pattern-matching logic, memory maps, and user customization — making it an excellent educational project for understanding:
- String manipulation
- Conditionals
- Memory handling with `map`
- File I/O with `fstream`
- Modular programming in C++

---

## 🚀 Features

- 💬 Predefined responses with randomized variation
- 🧠 Session-based memory (remembers name, age, favorite color, and food)
- 📚 Users can teach new phrases at runtime with `teach <keyword> <response>`
- 🗂️ Logs unknown inputs to `data/unknown_inputs.txt`
- 🔠 Case-insensitive input handling
- 📁 Clean and modular C++ project structure

---

## 🧱 Project Structure

```text
ChatMind/                     # Root folder of the project
├── src/
│   ├── main.cpp              # Entry point of the application
│   ├── chatbot.cpp           # Core chatbot logic (responses, memory, learning)
│   └── chatbot.h             # Header for the chatbot interface
├── data/
│   └── unknown_inputs.txt    # Logs unknown user inputs
├── build/                    # (Optional) Compiled output (created manually)
├── chatbot.exe               # Final compiled binary (on Windows)
├── README.md                 # Project documentation for GitHub

