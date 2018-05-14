/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package oracleconnection;

import java.sql.*;

/**
 *
 * @author Projector-PC-418
 */
public class OracleConnection {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        try {
            Class.forName("oracle.jdbc.driver.OracleDriver");

            Connection con = DriverManager.getConnection(
                    "jdbc:oracle:thin:@localhost:1521:xe", "st3", "123");

            Statement stmt = con.createStatement();

            ResultSet rs = stmt.executeQuery("select * from employee");
            while (rs.next()) {
                System.out.println(rs.getString(1) + "  " + rs.getString(2) + "  " + rs.getString(3)+" " +rs.getString(4)+" "+ rs.getString(5)+" " +rs.getString(6));
            }

            con.close();

        } catch (Exception e) {
            System.out.println(e);
        }

    }
}
