
shape = [
    [(0, 0), (1, 0), (1, -1)],
    [(0, 0), (0, 1), (1, 0)],
    [(0, 0), (1, 0), (1, 1)],
    [(0, 0), (0, 1), (1, 1)]
]

def is_placable(shape_index, height, width, y, x, gamemap):
    for point_index in range(3):
        dy, dx = shape[shape_index][point_index]
        if y + dy >= height or y + dy < 0:
            return False
        if x + dx >= width or x + dx < 0:
            return False
        if gamemap[y + dy][x + dx] is '#':
            return False
    return True

def place(shape_index, y, x, gamemap, point):
    for point_index in range(3):
        dy, dx = shape[shape_index][point_index]
        gamemap[y + dy][x + dx] = point

def place_empty(shape_index, y, x, gamemap):
    place(shape_index, y, x, gamemap, '.')

def place_block(shape_index, y, x, gamemap):
    place(shape_index, y, x, gamemap, '#')

def is_full(gamemap):
    for i in range(len(gamemap)):
        if '.' in gamemap[i]:
            return False
    return True

def get_next(y, x, gamemap):
    for i in range(y, len(gamemap)):
        if '.' in gamemap[i]:
            return i, gamemap[i].index('.')
    return None, None

def run(height, width, y, x, gamemap):
    if is_full(gamemap): return 1
    result = 0
    if gamemap[y][x] is '#':
        new_y, new_x = get_next(y, x, gamemap)
        result += run(height, width, new_y, new_x, gamemap)
    for shape_index in range(4):
        if not is_placable(shape_index, height, width, y, x, gamemap):
            continue
        place_block(shape_index, y, x, gamemap)
        new_y, new_x = get_next(y, x, gamemap)
        result += run(height, width, new_y, new_x, gamemap)
        place_empty(shape_index, y, x, gamemap)
    return result

if __name__ == "__main__":
    tc_cnt = int(input())
    for tc in range(tc_cnt):
        l = input().split()
        h = int(l[0])
        w = int(l[1])
        gamemap = []
        for i in range(h):
            gamemap.append(list(input()))
        print(run(h, w, 0, 0, gamemap))


def test_is_placable_1():
    gamemap = ["#.....#", "#.....#", "##...##"]
    gamemap = [list(s) for s in gamemap]
    assert not is_placable(0, 3, 7, 0, 0, gamemap)

def test_is_placable_2():
    gamemap = ["#.#####", "..#####", "#######"]
    gamemap = [list(s) for s in gamemap]
    assert is_placable(0, 3, 7, 0, 1, gamemap)

def test_is_placable_3():
    gamemap = ["..#####", ".######", "#######"]
    gamemap = [list(s) for s in gamemap]
    assert is_placable(1, 3, 7, 0, 0, gamemap)

def test_is_placable_4():
    gamemap = [".######", "..#####", "#######"]
    gamemap = [list(s) for s in gamemap]
    assert is_placable(2, 3, 7, 0, 0, gamemap)

def test_is_placable_5():
    gamemap = ["..#####", "#.#####", "#######"]
    gamemap = [list(s) for s in gamemap]
    assert is_placable(3, 3, 7, 0, 0, gamemap)

def test_is_full_1():
    gamemap = ["..#####", ".######", "#######"]
    gamemap = [list(s) for s in gamemap]
    assert not is_full(gamemap)

def test_is_full_2():
    gamemap = ["#######", "#######", "#######"]
    gamemap = [list(s) for s in gamemap]
    assert is_full(gamemap)

def test_1():
    gamemap = ["..#####", ".######", "#######"]
    gamemap = [list(s) for s in gamemap]
    assert run(3, 7, 0, 0, gamemap) == 1

def test_2():
    gamemap = ["#.....#", "#.....#", "##...##"]
    gamemap = [list(s) for s in gamemap]
    assert run(3, 7, 0, 0, gamemap) == 0 

def test_3():
    gamemap = ['#.....#', '#.....#', '##..###']
    gamemap = [list(s) for s in gamemap]
    assert run(3, 7, 0, 0, gamemap) == 2

def test_4():
    gamemap = ['##########', '#........#', '#........#', '#........#',
        '#........#', '#........#', '#........#', '##########' ]
    gamemap = [list(s) for s in gamemap]
    assert run(8, 10, 0, 0, gamemap) == 1514
    