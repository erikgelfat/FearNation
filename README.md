# 🎮 FearNation

**FearNation** is a gritty, Mortal Kombat–style fighting game written in **Turbo Assembler (TASM)** for real-mode DOS using **Mode X** (320×240, 256‑color VGA). This is a personal passion project pushing the limits of what’s achievable in 16‑bit Assembly—complete with custom sprite engines, collision detection, and hard-hitting combat mechanics.

---

## 🛠️ Features

- **Mode X VGA graphics engine**
  - Fast graphics primitives, planar memory writes, and palette control.
- **Frame timing & input loop**
  - VSync-synced frame loops using VGA retrace and mouse/keyboard input.
- **Sprite-based characters & stages**
  - Custom sprite pipelines: load `.PCX` images, blit to screen, animate frame-based sequences.
- **Hitboxes & collision**
  - 2D rectangular hitbox detection for punch, kick, block, and stun logic.
- **State machine AI**
  - CPU opponents with aggression, guard, hit, and recovery states.
- **Sound FX**
  - PC speaker + optional Sound Blaster integration (if available).

---

## 📂 Code Structure Overview


/include
├── video.asm ; Mode X init, pixel/line routines
├── sprite.asm ; load/blit sprite frames & palette
├── input.asm ; keyboard + mouse handling
├── main.asm ; frame loop, gamestate management
├── fighter.asm ; character routines, AI, hit detection
├── audio.asm ; simple PC‑speaker / SB driver
└── util.asm ; helper macros, timing, math routines

---

## ⚙️ Build & Run Instructions

Requirements:
DOSBox or real-mode DOS environment.
Turbo Assembler & Turbo Linker.

- run !complie.bat
- run rush.exe

---

## 📊 Current Progress & TODOs

✅ Frame engine & input loop
✅ Sprite loading & basic blitting
🚧 Fighting logic: punch/kick/hit/block
🚧 SoundBlaster support
🚧 X mode planes working properly
🚧 2 thread input
✅ Menus, character select, multiple fighters
🚧 Final polish & high-score tracking

---

## ❤️ Credits & License

Author: Erik Gelfat
License: MIT – feel free to fork, experiment, and contribute back!
Let me know if you'd like help setting up sound drivers, adding new stages, or optimizing your sprite routines. This README is designed to be informative, decorative, and supportive—ready to showcase your Assembly-level deep dive into retro graphics and gameplay!

