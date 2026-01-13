class Solution(object):
    def separateSquares(self, squares):
        events = []
        total_area = 0

        for x, y, l in squares:
            events.append((y, l))
            events.append((y+l, -l))
            total_area += l*l
        
        events.sort()
        target_area = total_area / 2.0
        
        curr_rate = 0
        area_below = 0
        prev_y = events[0][0]

        for y, delta in events:
            height = y - prev_y
            if height > 0:
                segment_area = curr_rate * height
                if area_below + segment_area >= target_area:
                    return prev_y + (target_area-area_below) / curr_rate
                area_below += segment_area
            
            curr_rate += delta
            prev_y = y