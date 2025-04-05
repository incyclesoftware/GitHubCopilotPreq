package com.incycle.servlet;

import java.io.IOException;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.incycle.utils.Utils;

@WebServlet("/test")
public class Test1 extends HttpServlet {
    private static final long serialVersionUID = 1L;

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        // Set request character encoding to UTF-8
        request.setCharacterEncoding("UTF-8");

        String input = request.getParameter("inputField");
        response.setContentType("text/html; charset=UTF-8");
        response.setCharacterEncoding("UTF-8");

        response.getWriter().println("<html><body>");
        response.getWriter().println("<h1>You entered: " + input + "</h1>");
        response.getWriter().println("</body></html>");

        Connection connection = Utils.getConnection("database/inventory.db");
        if (connection != null) {
            try {
                Statement statement = connection.createStatement();
                try {
                    ResultSet resultSet = statement.executeQuery("SELECT * FROM users");
         

                    response.getWriter().println("<table border='1'>");
                    response.getWriter()
                            .println("<tr><th>ID</th><th>Username</th><th>first name</th><th>last name</th></tr>");
                    while (resultSet.next()) {
                        int id = resultSet.getInt("id");
                        String name = resultSet.getString("username");
                        String firstName = resultSet.getString("first_name");
                        String lastName = resultSet.getString("last_name");
                        response.getWriter().println("<tr><td>" + id + "</td><td>" + name + "</td><td>" + firstName
                                + "</td><td>" + lastName + "</td></tr>");
                    }
                    response.getWriter().println("</table>");
                    resultSet.close();
                    statement.close();
                } catch (Exception e) {
                    response.getWriter().println("<p>Error 2: " + e.getMessage() + "</p>");
         
                }
            connection.close();
            } catch (Exception e) {
                response.getWriter().println("<p>Error 1: " + e.getMessage() + "</p>");
         
            }
        }
        else {
            response.getWriter().println("<p>Error: Unable to connect to the database.</p>");
         
        }
    }
}
