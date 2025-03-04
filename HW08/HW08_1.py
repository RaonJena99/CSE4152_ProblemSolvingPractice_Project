import numpy as np
from sympy import symbols, solve

class GoldenRectangle:
    def __init__(self, n):
        self.fibonacci_list = self.fibo(n)

    @staticmethod
    def fibo(n):
        results = [1]

        if n <= 1: 
            return results
        else:
            results = [1, 1]
            for i in range(2,n):
                tmp = results[i-1] + results[i-2]
                results.append(tmp)
        return results
    
    @staticmethod
    def right_operation(grid_cells, cur_rect_length, height, width, i, j):
        grid_cells[i:i + height, j + width - cur_rect_length:j + width] = cur_rect_length
        return grid_cells

    @staticmethod
    def down_operation(grid_cells, cur_rect_length, height, width, i, j):
        grid_cells[i + height - cur_rect_length:i + height, j:j + width] = cur_rect_length

        return grid_cells
    
    @staticmethod
    def left_operation(grid_cells, cur_rect_length, height, width, i, j):
        grid_cells[i:i + height, j:j + cur_rect_length] = cur_rect_length
        return grid_cells

    @staticmethod
    def up_operation(grid_cells, cur_rect_length, height, width, i, j):
        grid_cells[i:i + cur_rect_length, j:j + width] = cur_rect_length
        return grid_cells

    # Do not change this function name (get_golden_rectangle)
    def get_golden_rectangle(self):
        # TODO: Implement the logic to create the golden rectangle grid
        height, width = self.fibonacci_list[-1], self.fibonacci_list[-1] + self.fibonacci_list[-2]  
        grid_cells = np.zeros((height, width))

        direction = ['left', 'up', 'right', 'down']

        cur_height = height
        cur_width = width
        i0, j0, d = 0, 0, 0
        n = len(self.fibonacci_list)
        
        for k in range(n):
            sel = direction[d % 4]
            s = self.fibonacci_list[n - k - 1]

            if sel == 'right':
                grid_cells = self.right_operation(grid_cells, s, cur_height,cur_width, i0, j0)
                cur_width -= s

            elif sel == 'down':
                grid_cells = self.down_operation(grid_cells,s,cur_height,cur_width, i0, j0)
                cur_height -= s

            elif sel == 'left':
                grid_cells = self.left_operation(grid_cells,s,cur_height,cur_width, i0, j0)
                cur_width -= s
                j0 += s

            elif sel == 'up':
                grid_cells = self.up_operation(grid_cells,s,cur_height,cur_width, i0, j0)
                cur_height -= s
                i0 += s

            d += 1
        
        # Return the grid cells as an (H, W) ndarray
        return grid_cells
        
        
# Instructions: Complete only the class implementation. You may add print statements to test when using the "Run" button, 
# but only the class will be used for grading upon submission.

# n = 6
# golden_rectangle_instance = GoldenRectangle(n)
# golden_rectangle = golden_rectangle_instance.get_golden_rectangle()
# print(golden_rectangle)

# Explanation on the difference with @staticmethod:
# Using @staticmethod:
#   - Methods marked with @staticmethod do not need access to any instance-specific data, 
#     so they can be called directly from the class, e.g., GoldenRectangle.fibo(10).
#   - They do not access self or instance variables.
# Without @staticmethod:
#   - Methods without @staticmethod need an instance of the class to access instance-specific data (like self.fibonacci_list).
#   - They are called through an instance, e.g., golden_rectangle_instance.get_golden_rectangle().

