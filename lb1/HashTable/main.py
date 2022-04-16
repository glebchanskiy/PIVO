from HashTable import HashTable

tb = HashTable(10)

tb.add("levkov", ["12170041", "9.2", "11111111", "info1"])
tb.add("moshuc", ["12170047", "9.3", "22222222", "info2"])
tb.add("vasilkov", ["12170007", "9.4", "33333333", "info3"])
tb.add("vekeev", ["12170003", "9.5", "44444444", "info4"])
tb.add("dfdsfd", ["12170023", "10", "44444444", "info4"])
tb.add("levkov", ["12170076", "8", "77777777", "info2"])

print("\nХеш-таблица:")
tb.print_table()
print("fillfactor: ", tb.get_fill_factor(), "\n")

if not tb.element_is_empty("vekeev"):
    print("Элемент по ключу  vekeev - найден\n")
else:
    print("Элемент по ключу  vekeev - не найден\n")


tb.remove("vekeev")
tb.remove("dfdsfd")

print("\nХеш-таблица:")
tb.print_table()
print("fillfactor: ", tb.get_fill_factor(), "\n")

if not tb.element_is_empty("vekeev"):
    print("Элемент по ключу  vekeev - найден\n")
else:
    print("Элемент по ключу  vekeev - не найден\n")

tb.clear()

if tb.is_empty():
    print("таблица пуста\n")

tb_2 = HashTable(5)

tb_2.add("artem", ["12170041", "9.2", "11111111", "info1"])

if not tb_2.element_is_empty("artem"):
    print("Инофрмация по ключу artem: ", tb_2.get_data("artem"))
else:
    print("Инофрмация по ключу artem: не найдена")

tb_2.remove("artem")

if not tb_2.element_is_empty("artem"):
    print("Инофрмация по ключу artem: ", tb_2.get_data("artem"))
else:
    print("Инофрмация по ключу artem: не найдена")
