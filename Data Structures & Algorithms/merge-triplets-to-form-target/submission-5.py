class Solution:

    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        # Track if we can successfully match target[0], target[1], and target[2]
        found_x = found_y = found_z = False

        for x, y, z in triplets:
            # Greedy filter: Only consider triplets that do not exceed our target in ANY position
            if x <= target[0] and y <= target[1] and z <= target[2]:
                # If it's a safe triplet, check if it contributes the exact value we need
                if x == target[0]:
                    found_x = True
                if y == target[1]:
                    found_y = True
                if z == target[2]:
                    found_z = True

            # Shortcut: If all three target components are satisfied, we can stop early
            if found_x and found_y and found_z:
                return True

        return found_x and found_y and found_z