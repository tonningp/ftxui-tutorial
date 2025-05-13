# 🧪 Lab 1: Display a Custom Welcome Message with FTXUI

## 🎯 Objective

Update the provided C++ program using the FTXUI library so that it displays:

```
Hello, Welcome to FTXUI
```

This lab introduces component-based UI design in terminal applications using FTXUI, and reinforces how to pass data to components using constructors.

---

## 📂 Files Provided

- `main.cpp` — starter program with a `MainComponent` class
- `CMakeLists.txt` — for building the project with FTXUI (provided separately)

---

## 📝 Instructions

### 1. Open `main.cpp`.

In the `main()` function, find this line:

```cpp
auto main_component = std::make_shared<MainComponent>(&screen, "Main Message");
```

### 2. Change the second argument (the message string) to:

```cpp
"Hello, Welcome to FTXUI"
```

So the updated line becomes:

```cpp
auto main_component = std::make_shared<MainComponent>(&screen, "Hello, Welcome to FTXUI");
```

### 3. Save the file.

### 4. Build and run:

```bash
mkdir build
cd build
cmake ..
make
./main
```

### 5. Expected Output:

```
Hello, Welcome to FTXUI
------------------------
Press 'Q' or 'q' to quit.
```

---

## ✅ Learning Goals

- Understand how FTXUI components are created and initialized
- Learn how constructor parameters can be used to customize UI components
- Observe how rendering is tied to component state and `OnRender()`

---

## 🧠 Optional Challenges

- Change the message based on user input or a random quote
- Center and color the message using `| center | color(Color::Green)`
- Add a second constructor that includes a title

---

## 🛠 Troubleshooting

If the message doesn’t appear:

- Confirm you passed the message to the constructor in `main()`
- Rebuild using `make clean && make`
- Verify `m_message` is used in `OnRender()`

---

## 📚 Resources

- [FTXUI GitHub](https://github.com/ArthurSonzogni/FTXUI)
- [FTXUI Tutorial & Docs](https://arthursonzogni.com/FTXUI/)

---

**Instructor Note:** This lab introduces basic customization through constructor parameters. Future labs can explore buttons, events, layout composition, and real-time UI updates.
