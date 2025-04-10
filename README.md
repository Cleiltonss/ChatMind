# ChatMind 🤖💬

A lightweight and modular **C++ console chatbot** that learns from users, remembers personal facts, and logs unknown phrases for future improvement.

---

## 🚀 Features

- 💬 Predefined responses with randomized variation
- 🧠 Session-based memory (remembers name, age, favorite color, and food)
- 📚 Users can teach new phrases at runtime with `teach <keyword> <response>`
- 🗂️ Logs unknown inputs to `data/unknown_inputs.txt`
- 🔠 All text input is case-insensitive
- 📁 Cleanly structured and easily extendable C++ project

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

