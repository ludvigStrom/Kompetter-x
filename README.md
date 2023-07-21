# Kompetter-x
Stm32 based HID macro 4x4 keypad with magnetic encoder. 

**Roadmap:
* Define the Menu Structure: Start by defining the structure of your menu. This could be a simple list of options, or a more complex tree-like structure with submenus. Each menu item should have a name and a function that gets called when the item is selected.

* USB Encapsulation: Create a module that handles all the USB communication. This module should provide functions for sending different types of commands (e.g., volume up/down, key press, etc.). These functions will be called by the menu system when a certain option is selected.

* Display Encapsulation: Similarly, create a module for handling the display. This module should provide functions for displaying the current menu, highlighting the selected option, etc.

* Input Handling: You'll need a way to navigate through the menu and select options. This could be done using the keyboard and the encoder. For example, the encoder could be used to scroll through the options, and a certain key could be used to select an option. You'll need to write code that reads the input devices and updates the menu system accordingly.

* State Machine: Implement a state machine that keeps track of the current state of the system (e.g., which menu is currently being displayed, which option is selected, etc.). The state machine should update the state based on the input from the user and call the appropriate functions from the USB and display modules.

* Menu Functionality: Finally, implement the functionality for each menu option. This could involve sending a certain USB command, entering a submenu, etc.

* Remember to test each module and functionality as you implement it. This will make it easier to catch and fix bugs early on. Also, consider using version control (like Git) to keep track of your changes and make it easier to revert back if something goes wrong.

* This is a high-level roadmap and you might need to adjust it based on your specific requirements and constraints. Good luck with your project! 
