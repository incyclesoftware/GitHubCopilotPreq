<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Hello World</title>
</head>
<body>
    <h1>Hello, World!</h1>
    <form action="/test" method="post">
        <label for="inputField">Enter something:</label>
        <input type="text" id="inputField" name="inputField" required>
        <button type="submit">Submit</button>
    </form>
</body>
</html>