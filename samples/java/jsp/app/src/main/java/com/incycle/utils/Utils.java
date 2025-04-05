package com.incycle.utils;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Utils {
    public static Path locateDatabaseFile(String relativePath) {
        if (relativePath == null || relativePath.isEmpty()) {
            return null;
        }
        Path currentPath = Paths.get(relativePath).toAbsolutePath();
        while (currentPath != null) {
            if (Files.exists(currentPath) && Files.isRegularFile(currentPath)) {
                return currentPath;
            }
            currentPath = currentPath.getParent();
        }
        return null;
    }

    public static String getDatabasePath(String dbFile) {
        for (int i = 0; i < 3 && !Files.exists(Paths.get(dbFile)); i++) {
            dbFile = "../" + dbFile;
        }
        if (Files.exists(Paths.get(dbFile))) {
            return dbFile;
        }
        return null;
    }

    public static Connection getConnection(String dbFile) {
        String databasePath = getDatabasePath(dbFile);
        if (databasePath == null) {
            return null;
        }
        Connection conn = null;
        for (int i = 0; i < 3; i++) {
            try {
                conn = DriverManager.getConnection("jdbc:sqlite:" + databasePath);
            } catch (SQLException e) {
                try {
                    Thread.sleep(100);
                } catch (InterruptedException interruptedException) {
                    Thread.currentThread().interrupt(); // Restore the interrupted status
                }
            }
        } 
        return conn;
    }

}
