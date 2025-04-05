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
            System.err.println("Database file not found: " + dbFile);
            return null;
        }

        Connection conn = null;
        int maxRetries = 3;
        int retryDelay = 100; // Initial delay in milliseconds

        for (int i = 0; i < maxRetries; i++) {
            try {
                conn = DriverManager.getConnection("jdbc:sqlite:" + databasePath);
                break; // Exit loop if connection is successful
            } catch (SQLException e) {
                System.err.println("Attempt " + (i + 1) + " failed: " + e.getMessage());
                if (i == maxRetries - 1) {
                    // Log the error if it's the last retry
                    System.err.println("Failed to connect to database after " + maxRetries + " attempts.");
                } else {
                    try {
                        Thread.sleep(retryDelay);
                        retryDelay *= 2; // Exponential backoff
                    } catch (InterruptedException interruptedException) {
                        Thread.currentThread().interrupt(); // Restore the interrupted status
                        System.err.println("Retry interrupted. Exiting...");
                        break;
                    }
                }
            }
        }
        return conn;
    }

}
