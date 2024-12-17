# **Cub3D: My First RayCaster**
![Screenshot from 2024-12-17 14-20-17](https://github.com/user-attachments/assets/ad72ebe7-7e85-4385-a040-228cbbc4fa9c)

## **Project Description**

The objective of this project is to create a dynamic 3D view within a maze using **ray-casting** techniques, similar to the classic **Wolfenstein 3D**. We used the **MiniLibX** library to handle graphics, windows, and events.

---

## **How to Run the Project**

### **1. Compilation**
To compile the project, use the `Makefile` provided:
```bash
make all
```

### **2. Running the Game**
Run the game with a valid map file (`.cub` format) located in the `maps` folder:
```bash
./cub3D maps/ok_pioupiou.cub
```

---

## **Project Requirements**

### **Program Name**:
- `cub3D`

### **Key Features**:
1. **3D Representation**:
   - Use **ray-casting** to render a 3D dynamic view inside a maze.

2. **Window Management**:
   - Manage window events using MiniLibX:
     - **Arrow Keys**: Rotate the camera (look left/right).  
     - **W, A, S, D**: Move the player in the maze.  
     - **ESC Key**: Quit the game cleanly.  
     - **Close Button**: Quit the game when the window is closed.

3. **Textures**:
   - Display different wall textures for the **North**, **South**, **East**, and **West** walls.

4. **Floor and Ceiling Colors**:
   - Configure the floor and ceiling with RGB colors.

### **Map Configuration**:

1. The map file must use the `.cub` extension and adhere to the following format:
   - `0` : Empty space  
   - `1` : Wall  
   - `N`, `S`, `E`, `W` : Player start position and orientation.

2. **Map Example**:
   ```
   NO ./path_to_the_north_texture
   SO ./path_to_the_south_texture
   WE ./path_to_the_west_texture
   EA ./path_to_the_east_texture

   F 220,100,0
   C 225,30,0

   111111
   100101
   101001
   1100N1
   111111
   ```

3. **Map Rules**:
   - The map must be surrounded by walls (`1`).  
   - The player must have a valid starting position (`N`, `S`, `E`, `W`).  
   - The program must check for errors and quit with an explicit message if the map is invalid.

---

## **Demo of the Project**

<div align="center">
  <img src="./Docs/cube_3d_game.gif" alt="Project Demo">
</div>
