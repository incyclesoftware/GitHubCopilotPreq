package com.incycle.utils;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

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
        for(int i=0;i<3&&!Files.exists(Paths.get(dbFile));i++)
        {
            dbFile="../"+dbFile;
        }
        if (Files.exists(Paths.get(dbFile))) {
            return dbFile;
        }
        return null;
    }
}
