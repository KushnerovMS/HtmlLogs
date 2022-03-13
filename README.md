# HtmlLogs

Небольшая библиотека в помощь написанию цветных логов в html-формате.

## Использование

- Копировать перозиторий на компьютер.
- Командой `make libLogs.a` собрать библитотеку.
- Библиотеку и header Log.h положить в репозиторий с проектом и указывать дополнительную библиотеку при компилировании
- В с кодом, нуждающихся в логах подключить header Logs.h
- Запись в лог производится командами `Logs.error(), Logs.warn(), Logs.debug, Logs.trace`
- При необходимости можно создать еще файл с логами прямым созданием класса `Logs` с параметром имени файла.

## Примечания

Если не нравится дефолтное имя логов Logs.html, можно поменять в Log.h в строчке

  >6 const char DEFAULT_LOG_NAME[] = "Logs.html";
