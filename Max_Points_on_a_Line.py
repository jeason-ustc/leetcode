class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        len_points = len(points)
        if len_points <= 1:
            return len_points
        max_count = 0
        for index1 in range(0, len_points):
            p1 = points[index1]
            gradients = {}
            infinite_count = 0
            duplicate_count = 0
            for index2 in range(index1, len_points):
                p2 = points[index2]
                dx = p2.x - p1.x
                dy = p2.y - p1.y
                if 0 == dx and 0 == dy:
                    duplicate_count += 1
                if 0 == dx:
                    infinite_count += 1
                else:
                    g = float(dy) / dx   # take care
                    # seem like cannot do gradients[g] += 1 if key: g not exists
                    gradients[g] = (gradients[g] + 1 if gradients.has_key(g) else 1)
            if infinite_count > max_count:
                max_count = infinite_count
            for k, v in gradients.items():
                v += duplicate_count
                if v > max_count:
                    max_count = v
        return max_count
