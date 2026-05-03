# Лабораторная работа №02
## Работа с Git и GitHub

---

## Часть 1.
1.1. Создание пустого репозитория на GitHub

На сайте github.com создан новый репозиторий lab2h без README, .gitignore.

1.2. Настройка Git и создание локальной копии


```sh 
git config --global user.name "barsik20"
git config --global user.email "bars.070620077777@gmail.com"
cd barsik20/workspace/projects
mkdir homet
cd homet
git init
```

<details> <summary>📋 Вывод git init</summary>
Initialized empty Git repository in /root/barsik20/workspace/projects/homet/.git/
</details>


1.3. Первый коммит (README.md)
```sh 
echo "Home task" > README.md
git add README.md
git commit -m "new commit"
git branch -M main
git remote add origin https://github.com/barsik20/lab2h.git
git push -u origin main
```
<details> <summary>📋 Вывод git push</summary>
  <pre>
Username for 'https://github.com': barsik20
Password for 'https://barsik20@github.com':
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Writing objects: 100% (3/3), 222 bytes | 222.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/barsik20/lab2h.git
 * [new branch]      main -> main
branch 'main' set up to track 'origin/main'.
  </pre>
 </details>

1.4. Создание программы hello_world.cpp (плохой стиль)
```sh 
# cat > hello_world.cpp <<EOF
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world" << endl;
    return 0;
}
EOF
git add hello_world.cpp
git commit -m " hello_world.cpp с плохим стилем (с using namespace std)"
 ```
<details><summary>📄 Содержимое первой версии</summary>

#include <iostream>
using namespace std;

int main() {
    cout << "Hello world" << endl;
    return 0;
}
</details>

1.5. Добавление ввода имени пользователя
```sh 

cat > hello_world.cpp <<EOF
#include <iostream>
#include <string>
using namespace std;
int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello world from @" << name << endl;
    return 0;
}
EOF
git commit -am "Новое имя"
```

Теперь программа запрашивает имя пользователя и выводит приветствие.

 -am  автоматически добавляет изменения в файлах .
<details> <summary>📄 Содержимое второй версии</summary>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello world from @" << name << endl;
    return 0;
}
</details>

<details> <summary>📋 Вывод git commit</summary>
[main 555752a] Новое имя
 1 file changed, 5 insertions(+), 1 deletion(-)
</details>

1.6. Отправка изменений на GitHub и проверка истории
```sh
git push
```
Изменения отправлены в удалённый репозиторий.
<details> <summary>📋 Вывод git push</summary>
  <pre>
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 8 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 834 bytes | 834.00 KiB/s, done.
Total 6 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/barsik20/lab2h.git
   ff0a68f..555752a  main -> main
  </pre>
</details>

---
## Часть 2
2.1. Создание локальной ветки patch1
```sh
git checkout -b patch1
```
Создана новая ветка patch1 и выполнен переход на неё.

<details><pre>Switched to a new branch 'patch1'</pre></details>

2.2. Исправление кода: удаление using namespace std
```sh
cat > hello_world.cpp <<EOF
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
EOF
git add hello_world.cpp
git commit -m "Не используем using namespace"
```
2.3. Отправка ветки patch1 на GitHub
```sh
git push -u origin patch1
```
Ветка patch1 отправлена в удалённый репозиторий. После этого она доступна на GitHub.
<details> <summary>📋 Вывод git push</summary>
  <pre>
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 452 bytes | 452.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
remote:
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/barsik20/lab2h/pull/new/patch1
remote:
To https://github.com/barsik20/lab2h.git
 * [new branch]      patch1 -> patch1
branch 'patch1' set up to track 'origin/patch1'.

  </pre>
</details>

2.4. Добавление комментариев в код (ветка patch1)
```sh
cat > hello_world.cpp <<EOF
#include <iostream>
#include <string>

// Main function
int main() {
    // user's name
    std::string name;
    std::cout << "Enter your name: ";
    // entering your name
    std::cin >> name;
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
EOF
git add hello_world.cpp
git commit -m "Добавлены комментарии в код"
git push
```
2.5. Обновление ветки main после слияния
```sh
git checkout main
git pull origin main
```
<details> <summary>📋 Вывод git push</summary>
<pre>
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 421 bytes | 421.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/barsik20/lab2h.git
   bbf67ee..4198d16  patch1 -> patch1
</pre>
</details>

2.6. Просмотр истории коммитов
```sh
git log --oneline
```
<details> <summary>📋 Вывод git log --oneline после слияния patch1</summary>
<pre>
4198d16 (origin/patch1, patch1) Добавлены комментарии в код
bbf67ee Не используем using namespace
555752a (HEAD -> main, origin/main) Новое имя
44afa6a  hello_world.cpp с плохим стилем (с using namespace std)
ff0a68f new commit
</pre>
</details>

2.7. Удаление локальной ветки patch1
```sh
git branch -d patch1
```
2.8. Переключение на main и получение последних изменений

```sh
cd ~/barsik20/workspace/projects/homet
git checkout main
git pull origin main
```
<details>
  <pre>
    From https://github.com/barsik20/lab2h
     * branch            main       -> FETCH_HEAD
    Already up to date.
  </pre>
</details>

## Часть 3.
3.1. Создание новой локальной ветки patch2
```sh
git checkout -b patch2
```
<details> <summary>📋 Вывод</summary>

```sh
Switched to a new branch 'patch2'
```
</details>

3.2. Изменение code style с помощью утилиты clang-format
Установка clang-format
```sh
sudo apt update
sudo apt install clang-format -y
```
Применение форматирования
```sh
clang-format -style=Mozilla -i hello_world.cpp
```
3.3. commit, push, создание pull-request patch2 -> master
```sh
git add hello_world.cpp
git commit -m "Форматирование кода в стиле Mozilla с помощью clang-format"
git push -u origin patch2
```
<details> <summary>📋 Вывод коммита и push</summary>
<pre>
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 442 bytes | 442.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote:
remote: Create a pull request for 'patch2' on GitHub by visiting:
remote:      https://github.com/barsik20/lab2h/pull/new/patch2
remote:
To https://github.com/barsik20/lab2h.git
 * [new branch]      patch2 -> patch2
branch 'patch2' set up to track 'origin/patch2'.
</pre>
</details>

3.4. В ветке main в удалённом репозитории измените комментарии






```sh
git checkout main

cat > hello_world.cpp <<EOF
#include <iostream>
#include <string>
// Главная функция
int main()
{
    // имя пользователя
    std::string name;
    // Ввод имени
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
EOF



git add hello_world.cpp
git commit -m "Change comments to Russian language"
git push


```
<details> <summary>📄 Файл после изменения комментариев</summary>
  <pre>
    #include <iostream>
    #include <string>
    // Главная функция
    int main()
    {
        // имя пользователя
        std::string name;
        // Ввод имени
        std::cout << "Enter your name: ";
        std::cin >> name;
        std::cout << "Hello world from @" << name << std::endl;
        return 0;
    }
    EOF
  </pre>
</details>

3.5. Убедиться, что в pull-request появились конфликты

После изменения комментариев в ветке main страница pull request на GitHub обновилась, и появилось сообщение:
«This branch has conflicts that must be resolved».

3.6. Локально выполнить pull + rebase
```sh
git checkout patch2
git fetch origin
git rebase origin/main
```

<details> <summary>⚠️ Сообщение о конфликте</summary>
<pre>
Auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
error: could not apply 3578564... Форматирование кода в стиле Mozilla с помощью clang-format
</pre>
</details>
Чтобы исправить ошибки воспользуемся командой nano
<details> <summary>Исправление ошибки</summary>
  
```sh
nano hello_world.cpp
```
Удаляем конфликтные маркеры и получаем следующий код

```sh
#include <iostream>
#include <string>

int main() {
    // Переменная для хранения
    std::string name;
    // Ввод имени
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from @" << name << std::endl;
    return 0;
}
```
</details>
После исправления конфликта

```sh
git add hello_world.cpp
git rebase --continue
```

3.7. Сделать force push в ветку patch2

``` sh
git push --force origin patch2
```

Отправляет изменённую (после rebase) ветку patch2 в удалённый репозиторий, перезаписывая её историю.
<details> <summary>📋 Вывод force push</summary>
<pre>
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 396 bytes | 396.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/barsik20/lab2h.git
 + 3578564...3c095f3 patch2 -> patch2 (forced update)
</pre>
</details>
На GitHub нажата кнопка «Merge pull request», затем «Confirm merge». Ветка patch2 на GitHub удалена.

Удаление ветки patch2:
```sh
git branch -d patch2
git push origin --delete patch2
git remote prune origin
git branch -a (проверка на отсутствие веток)
```


3.8. Локальное обновление main

```sh
git checkout main
git pull origin main
git log --oneline --graph --all
```
<details> <summary>📋 Финальная история коммитов</summary>
<pre>

*   63bfa9e (HEAD -> main, origin/main) Merge pull request #2 from barsik20/patch2
|\
| * 3c095f3 Форматирование кода в стиле Mozilla с помощью clang-format
|/
* 18ac782 Изменены комментарии в main
* b33ad56 Поменяли язык
| * 4198d16 (origin/patch1) Добавлены комментарии в код
| * bbf67ee Не используем using namespace
|/
* 555752a Новое имя
* 44afa6a  hello_world.cpp с плохим стилем (с using namespace std)
* ff0a68f new commit
</pre>
</details>
P.S. Я заметил что все комиты идут сверху вниз от самого последнего до самого первого


