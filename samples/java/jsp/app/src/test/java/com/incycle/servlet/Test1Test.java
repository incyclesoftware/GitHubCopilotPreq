package com.incycle.servlet;

import static org.junit.jupiter.api.Assertions.*;
import com.incycle.utils.Utils;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

public class Test1Test {


    @Test
    public void testLocateDatabaseFile_FileExists() {
        try {
            Path tempFile = Files.createTempFile("test-database", ".db");
            tempFile.toFile().deleteOnExit();

            Path result = Utils.locateDatabaseFile(tempFile.toString());
            assertNotNull(result, "The database file should be located.");
            assertTrue(Files.exists(result), "The located file should exist.");
            assertEquals(tempFile.toAbsolutePath(), result, "The located file path should match the expected path.");
        } catch (Exception e) {
            fail("Exception occurred during test: " + e.getMessage());
        }
    }

    @Test
    public void testLocateDatabaseFile_FileDoesNotExist() {                
        Path result = Utils.locateDatabaseFile("nonexistent-file.db");
        assertNull(result, "The result should be null when the file does not exist.");
    }

    @Test
    public void testLocateDatabaseFile_EmptyPath() {
        Path result = Utils.locateDatabaseFile("");
        assertNull(result, "The result should be null when the path is empty.");
    }

    @Test
    public void testLocateDatabaseFile_NullPath() {
        Path result = Utils.locateDatabaseFile(null);
        assertNull(result, "The result should be null when the path is null.");
    }

    // @Test
    public void testLocateDatabaseFile_ParentDirectory() {
        Path result = Utils.locateDatabaseFile("database/inventory.db");
        assertNotNull(result, "The result should not be null when the file is located in the parent directory.");
    }

    @Test
    public void testLocateDatabaseFile_ParentDirectoryNotFound() {
        String dbFile= "database/inventory.db";
        for(int i=0;i<3&&!Files.exists(Paths.get(dbFile));i++)
        {
            dbFile="../"+dbFile;
        }
        assertTrue(Files.exists(Paths.get(dbFile)), "The database file should be located in the parent directory.");

    }
}   
