﻿# Проект: «Система трансляции экрана ПК преподавателя, раздачи файлов и текстовых сообщений на рабочие ПК студентов»

Группа, ответственная за чат для приложения.

Ссылка на сайт: http://facassanxt.ru:5000/

+ Необходимо установить для запуска сервера (flask, flask_socketio, flask_sockets, websockets).
+ Команды для установки:
  + pip install flask
  + pip install flask_socketio
  + pip install flask_sockets
  + pip install websockets


## Участники

| Учебная группа | Имя пользователя | ФИО                      |
|----------------|------------------|--------------------------|
| 181-352       | @GregoryBaranov       | Баранов  Г.А.              |
| 181-352        | @Facassanxt     | Стебло А.С.              |
| 181-352        | @Xom9k1337       | Захаров В.А. |
| 181-352        | @GETREKT1620     | Константинов Д.А.              |
| 181-352        | @TimurChikishev       | Чикишев Т.В. |

## Личный вклад участников

### Баранов  Г.А.

+ Главный разработчик flask сервера
  + создал flask сервер выдающий web страницу чата 
  + протестировал и настроил web сокет соединениe
+ Второй разработчик HTML/JS
  + модернизировал web версию чата
    + добавил кнопку сворачивания/разворачивания чата
----
### Стебло А.С.  

+ Главный разработчик HTML/JS
  + создал начальную web версию чата и учавствовал в дальнейшей модернизации
    + настроил дизайн через bootstrap
  + ???
+ Второй разработчик flask сервера
  + модернизировал flask сервер
    + настроил кодировку
    + запретил html разметку
----
### Захаров В.А.

+ Помощник главного разработчика flask сервера
  + помогал в разработке flask сервера
+ Помощник главного разработчика HTML/JS 
  + помогал в разработке HTML/JS
    + настроил дизайн через bootstrap и scrollbar
+ Тестировщик
  + проверял нагрузку на сервер
    + нагружал сервер запросами и анализировал сеть
    + установил макасимальный размер сообщения, которое сервер может обработать
+ Документация
----
### Константинов Д.А. 

+ Второй разработчик клиентского приложения
  + На ранней стадии проекта, до перехода сервера на web socket'ы создал полностью 
  работоспособное приложение, основанное на принципе отправки get-запросов по протоколу http
  + оптимизация кода
  + протестировал и настроил сокет-соединениe
----
### Чикишев Т.В.
+ Главный разработчик клиентского приложения
  + модернизировал клиентское приложение
    + помогал в настройке сокет соединения
    + добавил окно настроек
    + добавил кастомную строку заголовка
    + добавил имена 
