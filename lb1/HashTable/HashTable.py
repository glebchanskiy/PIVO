class HashTable(object):
    hashTable = []
    tb_capacity = 0          # размер таблицы
    el_count = 0             # кол-во занятых ячеек таблицы

    def __init__(self, tb_capacity: int):
        self.tb_capacity = tb_capacity
        self.hashTable = [[0], ] * tb_capacity

    def hash_function(self, key: str) -> int:
        key = key.lower()
        hash_value = 5381
        for c in key:
            hash_value = ((hash_value << 5) + hash_value) + ord(c)
        return hash_value % self.tb_capacity

    def add(self, key: str, data: list):
        """
        Дабавляет в таблицу информацию по ключу
        """
        index = self.hash_function(key)
        if self.hashTable[index] != [0]:
            self.hashTable[index] += [data]
        else:
            self.hashTable[index] = [data]
            self.el_count += 1
        
        print("По ключу: " + key + "  добавлена информиация: ", data)

    def remove(self, key: str):
        """
        Удаляяет ячейку таблицы по ключу
        """
        index = self.hash_function(key)
        self.hashTable[index] = [0]
        self.el_count -= 1

        print("Информация по ключу: " + key + " - удалена")

    def clear(self):
        """
        Стирает таблицу
        """
        self.hashTable = [[0], ] * self.tb_capacity
        self.el_count = 0
        print("таблица очищена")

    def print_all_table(self):
        """
        Выводит в консоль всю таблицу в форматированном виде (со стрелочками)
        """
        for el_list in self.hashTable:
            s = ""
            for item in el_list:
                if item == 0:
                    print(item)
                    break
                else:
                    s += str(item) + " -> "
            if s != "":
                print(s + "null")
        print()

    def print_table(self):
        """
         Выводит в консоль всю таблицу в форматированном виде (со стрелочками)
         !Кроме пустых ячеек!
        """
        if self.el_count == 0:
            print("table is empty")
            return
        for el_list in self.hashTable:
            s = ""
            for item in el_list:
                if item != 0:
                    s += str(item) + " -> "
            if s != "":
                print(s + "null")
        print()

    def get_data(self, key: str) -> list:
        """
        Возвращает список по ключу
        """
        index = self.hash_function(key)
        return self.hashTable[index]

    def element_is_empty(self, key: str) -> bool:
        """
        Возращает false - если ячейки с таким ключом не существует
        """
        index = self.hash_function(key)
        return self.hashTable[index] == [0]

    def is_empty(self) -> bool:
        """
        Возращает false - если таблица пустая
        """
        return self.el_count == 0

    def get_fill_factor(self) -> float:
        """
        Возвращает отношенеие кол-ва занятых ячеек таблицы к общему числу ячеек
        """
        return self.el_count / self.tb_capacity
