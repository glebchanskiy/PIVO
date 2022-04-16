class Graph:
    def __init__(self, m: list) -> None:
        self.graph = []
        self.vertices = 0

        for column in m:
            self.graph.append(column)
            self.vertices += 1

    def is_safe(self, v: int, pos: int, path: list) -> bool:

        # Если вершина не смежна с предыдущей
        if self.graph[path[pos - 1]][v] == 0:
            return False

        # Если текущая вершина в пути(path)
        for vertex in path:
            if vertex == v:
                return False

        return True

    def hamilton_cycle_util(self, path: list, pos: int) -> bool:
        # Базовый случай. Если все вершины в пути(path)
        if pos == self.vertices:
            # Если последняя вершина смежна с первой, то цикл существует
            return self.graph[path[pos - 1]][path[0]]  # == 1

        # v = 1, 2, 3, 4
        for v in range(1, self.vertices):
            #
            if self.is_safe(v, pos, path):
                path[pos] = v

                if self.hamilton_cycle_util(path, pos + 1):
                    return True

                # Откатываем вершину, если гамильтонов цикл не получен
                path[pos] = -1

        return False

    def hamilton_cycle(self) -> bool:
        path = [-1] * self.vertices
        # Поиск начинаем с нулевой вершины
        # в данном случае это не принципиально тк граф неор.
        path[0] = 0

        if self.hamilton_cycle_util(path, 1):
            # Если гамильтонов цикл найден
            print("Найден гамильтонов цикл: ")
            for vertex in path:
                print(vertex, end=" -> ")
            print(path[0], "\n")
            return True
        else:
            # Если гамильтонов цикл НЕ найден
            print("Гамильтонов цикл не обнаружен\n")
            return False
