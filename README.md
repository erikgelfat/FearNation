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
