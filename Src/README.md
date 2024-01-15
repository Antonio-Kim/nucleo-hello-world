# Starting out STM32 Nucleo Boards without HAL

---

This is a guide on how to create a "Hello world" project using STMicroelectronics' Nucleo boards. The project simply blinks its LED on the board, but without using Hardware Abstract Language (HAL). As of the time of writing, the program uses STM32CubeIDE version 1.12.1, and **Nucleo L476RG**. This guide should give help on how to work with any Nucleo boards, but cannot guarantee that it will work on all the boards, nor any new ones. This is merely a guide on how to approach writing a program without HAL.

The guide will refer to documentation provided by STMicroelectronics many times, so please read them as you go along. While it's not necessary, visual representation and charts are shown in the documentation which will describe the process and understanding documentation better.

## Background

---

Starting out with user guide of the board, we'll need to locate the LED on the board to blink. The Nucleo board has few LED on it, but the LED in discussion is the User LED, or LD2 in the documentation. Page 13 of the user manual in this repo shows the LED we're going to program.

Before doing so, here are some of the topics that are important to understand before starting to program: **buses, memory maps and registers**.

There are two major buses used in this guide to program: AHB and APB. AHB stands for Advanced High Performance, and APB stands Advanced Peripheral Bus. This guide will not go into details on what they are, but both buses are needed to understand which registers/ports are connected to the bus. On the Nucleo board's datasheet, search for block diagram to location how each ports are connected to different buses. Page 17 of the datasheet, Figure 1, shows the diagram in discussion. We will refer back to the buses shortly.

The second important concept is the memory mapping of the chip. Each of the peripherals that are available to the board are mapped onto small part of the board's memory, and the peripherals are controlled by the buses. Thus, to program specific peripherals, we need to first find out where the peripherals are located in the memory, and which buses are used to control them. Usually, peripherals start from 0x4000_000. After locating the peripheral(s) we want to use, we then also need to figure out the clock that the peripherals use. Reset and Clock Control is the component that is used to enable the peripherals. Specifically, as we will see later on, Clock Enable register is used to - as name suggest - enable the peripheral(s) that we are going to use.
