# Тема занятия
1. Повторение одномерных динамических массивов
2. Повторение и доработка многомерных динамических массивов
3. Рекурсия. Как пример (Ханойские башни)
   
  **Рекурсия** — это подход в программировании, при котором функция вызывает саму себя для решения задачи, разбивая её на более мелкие подзадачи того же типа.\
  Она особенно полезна для задач, которые можно разделить на повторяющиеся шаги.
   
  ## Основные компоненты рекурсии
  
   - Базовый случай — условие, при котором рекурсия останавливается. Без него возникнет бесконечный цикл.

   - Рекурсивный случай — шаг, на котором функция вызывает себя с изменёнными параметрами.
   
  ## Плюсы и минусы рекурсии
  
  ✅ Плюсы:

   - Упрощает код для задач с вложенной структурой (обход деревьев, графов, анализ директорий).

   - Позволяет элегантно решать задачи, которые естественно описываются рекурсивно.

  ❌ Минусы:

   - Риск переполнения стека вызовов (при большой глубине рекурсии).

   - Неэффективность по памяти и времени в некоторых случаях (например, числа Фибоначчи).

  ## Рекурсия vs Итерация
    
   - Рекурсия часто делает код лаконичнее, но может быть менее эффективной.

   - Итерация (циклы) обычно экономит память и работает быстрее.
   
  ## Советы по использованию
  
  - Всегда определяйте базовый случай.

  - Убедитесь, что рекурсия сходится (параметры движутся к базовому случаю).

  - Для оптимизации используйте мемоизацию (сохранение результатов дорогих вычислений).

  - Внимание к глубине рекурсии - она ограничена.
   
