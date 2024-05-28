# מטלה 2 - גרפים והעמסת אופרטורים

פרויקט זה הוא הרחבה של הפרויקט הקודם. בפרויקט זה, הוספנו השוואות ופעולות חשבון

## פרטי הפרויקט

- **סטודנטית:** 314923822
- **אימייל:** morberger444@gmail.com

## סקירה

הפרויקט מכיל שני מחלקות ראשיות:

- **Graph (גרף)**: מייצג מבנה נתונים של גרף ממטריצות מאפשר לטעון גרף ולהדפיס מידע על הגרף, לבצע פעולות חשבון והשוואות בין גרפים שונים
- **Algorithms (אלגוריתמים)**: מכיל אלגוריתמים לביצוע על גרפיים

  #פעולות עיקריות:
  - חיבור: הוספת אחד, או חיבור של שני גרפים. האופרטורים של חיבור לגרפים הם: +=, +. האופרטור של הוספת 1: ++
  - החיבור + מחבר שני גרפים שונים ואת התוצאה מכניס לגרף בצד השמאלי של =, =+ מוסיף את הגרף הימני לגרף השמאלי
  - חיסור: החסרת אחד, או חיסור של שני גרפים. האופרטורים של חיסור לגרפים הם: -=, -. החסרת של הוספת 1: --
  - החיסור - מחסר את הגרף השני מהגרף הראשון ואת התוצאה מכניס לגרף בצד השמאלי של =, =- מחסר את הגרף הימני מהגרף השמאלי
  - כפל בין גרפים מתבצע עם *, כפל עם סקלר * *=
  - הכפל * מכפיל שני גרפים שונים ואת התוצאה מכניס לגרף בצד השמאלי של =, =* מכפיל את הגרף הימני בגרף השמאלי
  - חילוק עם סקלר הוא /, מתבצעת בדיקה כי המספר שונה מ0, מחלק כל ערך בגרף בסקלר שהוכנס
    #השוואות:
    - שווה: האם הגרפים שווים ==
    - שונה: האם הגרפים שונים !=
    - האם גרף מסויים בעל משקל יותר גדול, קטן: > <
    - האם גרף מסויים בעל משקל יותר גדול, קטן או שווה: => =<
    - אני קובעת האם גרף מסויים גדול מהשני על ידי בדיקה אם מספר הקשתות בגרף הנוכחי גדול ממספר הקשתות בגרף השני


## שימוש


1. **כלול קבצי כותרת**: כלול את קבצי הכותרת `Graph.hpp` ו־`Algorithms.hpp` בפרויקט.
2. **יצירת מופעי גרף**: צור מופעים של מחלקת `Graph` וטען גרפים באמצעות שיטת `loadGraph`.
3. **שימוש בשיטות אלגוריתמיות**: קרא לשיטות הסטטיות של מחלקת `Algorithms` כדי לבצע אלגוריתמים גרפיים שונים על אובייקטי הגרף שנטענו.

   ## הרצה
- Run command:
- make run
- ./demo

## בדיקה 
- Run command:
- ./test
   צפוי לראות ללא הודעת שגיאה
