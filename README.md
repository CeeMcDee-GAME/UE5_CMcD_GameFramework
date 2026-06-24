# UE5_CMcD_GameFramework
**Decoupled C++ Gameplay Framework**

This project is built around one core rule: "keep things separate". Instead of packing all the logic inside a single player file, this framework uses modular C++ pieces to handle equipment, stats, and quests independently. The backend systems talk to the UI using a "megaphone" system (delegates), meaning you can completely swap out the menus or update the code without breaking the game!

# Video Demonstration
Watch the Gameplay Demo on YouTube!

[![Watch the Gameplay Demo on YouTube](https://img.youtube.com/vi/ftIABapH3Ik/0.jpg)](https://www.youtube.com/watch?v=ftIABapH3Ik)

# Key Architectural Features

**Event-Driven Subsystems:** The game uses a UQuestSubsystem to handle global state evaluation and quest tracking.

**Componentized Logic:** Inventory, data table lookups, and modifier calculations are all cleanly contained inside a standalone Scene and Actor Components, making the logic use flexible across player and AI actors alike.

**Decoupled UI Layering:** The UI utilizes dynamic multicast delegates to broadcast system-wide data updates to its listeners. This also ensures that the "Main Menu" HUD renders data fluidly without any hard references to other C++ Classes.

**One-Way State Locks:** The game implements strict data tracking to protect quest progression and prevent quest progress from accidentally resetting. It also manages data lookups from custom data tables to track the name, status, and flavor text for the active quest.
