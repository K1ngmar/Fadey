
<p align="center">
  <img alt="Really cool fadey banner" src="./img/fadey.png" />
</p>

# 🌈 Fadey
#### ✨ Your best friend when it comes to making your output beautiful ✨

# 📦 Content:
* [About](#-about)
* [Requirements](#-requirements)
* [Installation](#%EF%B8%8F-installation)
* [Features](#-features)
* [Performance](#%EF%B8%8F-performance)

# 📝 About:

Fadey will make your output into rainbows °˖✧◝(⁰▿⁰)◜✧˖°

# 📋 Requirements:
This project uses **ANSI 256 colors module**
```bash
# install ansi 256 color module:
$ npm install --save ansi-256-colors
```

# ⚙️ Installation:
```bash
# Clone:
$ git clone https://github.com/K1ngmar/Fadey.git

# Compile:
$ make -C Fadey/
```
>By running **MAKE** in this repository it will create a *static* library called `libfadey.a`.  
>The header is located at `{install_dir}/Fadey/includes/fadey.hpp`
```text
/Fadey/
├── includes/
│   └── fadey.hpp
├── libfadey.a
├── Makefile
└── ...
```

# ✅ Features:

> Everything is in the namespace `km`  
> Be aware that Fadey calls `srand(time(NULL));` once before main gets called!

* A global named `fadey` with `std::cout` as output stream

* The fade will continue across calls
  ```c++
  // example:
  for (size_t i = 0; i < 42; i++)
    km::fadey << "The fade continues across calls :O" << std::endl;
  ```
  > note that if you have a lot of difference in `line length` it will work best if you pass them as a *single* string
  <img alt="Really cool fadey banner" src="./img/fade across calls.png" style="float:right;height:85px;" />

* A constructor with auto reset turned `off` by default and an output stream set to `std::cout` by default
  ```c++
  // prototype:
  Fadey(bool auto_reset = false, std::ostream& stream = std::cout);
  ```

* Fade pattern starts at a random position by default

* Fadify function, that will turn your string into a rainbow
  ```c++
  // prototype:
  std::string fadify(std::string to_fade);

  // used like:
  std::string faded = km::fadey.fadify("I am about to get faded");
  ```

* An output stream for strings that will fadify the string ánd write it to stream
  ```c++
  // prototype:
  std::ostream& operator << (Fadey&, std::string);
  
  // used like:
  km::fadey << "This is going to be faded :D" << std::endl;
  ```

* An `auto reset` feature which will reset the fade patern to its original state every time 

  * A function to turn auto reset `on` and/or `off`
    ```c++
    // prototype:
    void	set_auto_reset(bool auto_reset);

    // used like:
    km::fadey.set_auto_reset(true);  // turn auto reset on
    km::fadey.set_auto_reset(false); // turn auto reset off
    ````

  * Toggle auto reset
    ```c++
    // prototype:
    void  toggle_auto_reset(void);

    // used like:
    km::fadey.toggle_auto_reset();
    ```
    > note that if you turn auto reset `on` the fade pattern will instantly be reset to its starting state
  
*  New seed
    ```c++
    // prototype:
    void	new_seed();

    // used like:
    km::fadey.new_seed();
    ```
    > note that this will not call `srand();`


# ❗️ Performance:
> Currently Fadey is very slow, I would **NOT** recommend using it if speed is important
