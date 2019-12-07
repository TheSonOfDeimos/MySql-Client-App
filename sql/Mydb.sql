-- MySQL dump 10.13  Distrib 8.0.18, for macos10.14 (x86_64)
--
-- Host: localhost    Database: mydb
-- ------------------------------------------------------
-- Server version	8.0.18

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `enrollee_doc_list`
--

DROP TABLE IF EXISTS `enrollee_doc_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `enrollee_doc_list` (
  `id` int(11) NOT NULL,
  `atestat` tinyint(4) DEFAULT NULL,
  `passport_copy` tinyint(4) DEFAULT NULL,
  `medical_form` tinyint(4) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `enrollee_doc_list`
--

LOCK TABLES `enrollee_doc_list` WRITE;
/*!40000 ALTER TABLE `enrollee_doc_list` DISABLE KEYS */;
INSERT INTO `enrollee_doc_list` VALUES (1,0,0,0),(2,1,0,0),(3,NULL,NULL,NULL),(4,NULL,NULL,NULL);
/*!40000 ALTER TABLE `enrollee_doc_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `enrollee_information`
--

DROP TABLE IF EXISTS `enrollee_information`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `enrollee_information` (
  `id` int(11) NOT NULL,
  `first_name` char(20) NOT NULL,
  `second_name` char(20) NOT NULL,
  `spec_num` int(11) NOT NULL,
  `exam_score` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `spec_num_idx` (`spec_num`),
  CONSTRAINT `doc_list` FOREIGN KEY (`id`) REFERENCES `enrollee_doc_list` (`id`),
  CONSTRAINT `exam_list1` FOREIGN KEY (`id`) REFERENCES `exam_list` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `id` FOREIGN KEY (`id`) REFERENCES `personal_enrollee_information` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `spec_num` FOREIGN KEY (`spec_num`) REFERENCES `specialisation_list` (`spec_num`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `enrollee_information`
--

LOCK TABLES `enrollee_information` WRITE;
/*!40000 ALTER TABLE `enrollee_information` DISABLE KEYS */;
INSERT INTO `enrollee_information` VALUES (1,'Poman','Pavlov',911,256),(2,'Margarita','Los',11,250),(3,'Nick','Morozov',23,230),(4,'Oleg','Nikiforov',911,251);
/*!40000 ALTER TABLE `enrollee_information` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `exam_list`
--

DROP TABLE IF EXISTS `exam_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `exam_list` (
  `id` int(11) NOT NULL,
  `math` int(11) DEFAULT NULL,
  `physics` int(11) DEFAULT NULL,
  `biology` int(11) DEFAULT NULL,
  `chemestry` int(11) DEFAULT NULL,
  `history` int(11) DEFAULT NULL,
  `russian` int(11) DEFAULT NULL,
  `english` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `exam_list`
--

LOCK TABLES `exam_list` WRITE;
/*!40000 ALTER TABLE `exam_list` DISABLE KEYS */;
INSERT INTO `exam_list` VALUES (1,546,0,435,345,435,435,345),(2,1,1,1,1,1,1,1),(3,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(4,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(11,1,1,1,1,1,1,1),(23,1,1,1,1,1,1,1),(911,45,0,100,100,1,1,1);
/*!40000 ALTER TABLE `exam_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `personal_enrollee_information`
--

DROP TABLE IF EXISTS `personal_enrollee_information`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `personal_enrollee_information` (
  `id` int(11) NOT NULL,
  `passport` bigint(20) DEFAULT NULL,
  `date_of_birth` date DEFAULT NULL,
  `place_of_birth` char(45) DEFAULT NULL,
  `address` char(45) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `personal_enrollee_information`
--

LOCK TABLES `personal_enrollee_information` WRITE;
/*!40000 ALTER TABLE `personal_enrollee_information` DISABLE KEYS */;
INSERT INTO `personal_enrollee_information` VALUES (1,345346,'1999-09-11','spb','spb'),(2,0,'1999-08-02','',''),(3,0,'1999-09-11','Saint-Petersburg','Here'),(4,0,'1998-11-23','Tambov','Moscowsy pr. 23');
/*!40000 ALTER TABLE `personal_enrollee_information` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `specialisation_list`
--

DROP TABLE IF EXISTS `specialisation_list`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `specialisation_list` (
  `spec_num` int(11) NOT NULL,
  `specialisation` char(45) DEFAULT NULL,
  `budget_places` int(11) DEFAULT NULL,
  `self_paid_places` int(11) DEFAULT NULL,
  PRIMARY KEY (`spec_num`),
  CONSTRAINT `exam_list` FOREIGN KEY (`spec_num`) REFERENCES `exam_list` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `specialisation_list`
--

LOCK TABLES `specialisation_list` WRITE;
/*!40000 ALTER TABLE `specialisation_list` DISABLE KEYS */;
INSERT INTO `specialisation_list` VALUES (11,'Programming',45,80),(23,'Menegmant',50,50),(911,'Dantist',2,200);
/*!40000 ALTER TABLE `specialisation_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping events for database 'mydb'
--

--
-- Dumping routines for database 'mydb'
--
/*!50003 DROP PROCEDURE IF EXISTS `add_all_enrollee_info` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `add_all_enrollee_info`(in id_ INT, in f_name_ CHAR(20), in s_name_ CHAR(20), in score_ INT, in spec_ INT,
																	in pas_ BIGINT(20), in dofb_ DATE, in pofb_ CHAR(45), in addr_ CHAR(45),
                                                                    in atest_ boolean, in pass_cpy_ boolean, mf_ boolean,
                                                                    in math_ INT, in ph_ INT, in bio_ INT, in chem_ INT, in his_ INT, in rus_ INT, in en_ INT)
BEGIN
	DECLARE math_v INT;
    DECLARE ph_v INT;
    DECLARE bio_v INT;
    DECLARE chem_v INT;
    DECLARE his_v INT;
    DECLARE rus_v INT;
    DECLARE en_v INT;
    
    SELECT math INTO math_v FROM mydb.exam_list WHERE id = spec_;
    SELECT physics INTO ph_v FROM mydb.exam_list WHERE id = spec_;
    SELECT biology INTO bio_v FROM mydb.exam_list WHERE id = spec_;
    SELECT chemestry INTO chem_v FROM mydb.exam_list WHERE id = spec_;
    SELECT history INTO his_v FROM mydb.exam_list WHERE id = spec_;
    SELECT russian INTO rus_v FROM mydb.exam_list WHERE id = spec_;
    SELECT english INTO en_v FROM mydb.exam_list WHERE id = spec_;
    
    if math_v <= math_ AND ph_v <= ph_ AND bio_v <= bio_ AND chem_v <= chem_ AND his_v <= his_ AND rus_v <= rus_ AND en_v <= en_
    then
		if NOT EXISTS(SELECT id FROM mydb.enrollee_information WHERE id = id_)
		then
			call add_enrollee_info(id_, f_name_, s_name_, score_, spec_);
		else
			UPDATE mydb.enrollee_information SET first_name = f_name_, second_name = s_name_, exam_score = score_, spec_num = spec_ WHERE id = id_;
		end if;
        call add_enrolle_private(id_, pas_, dofb_, pofb_, addr_);
		call add_doc_list(id_, atest_, pass_cpy_, mf_);
		call add_score(id_, math_, ph_, bio_, chem_, his_, rus_, en_);
    end if;
    
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `add_doc_list` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `add_doc_list`(in id_ INT, in atest_ boolean, in pass_cpy_ boolean, mf_ boolean)
BEGIN
    UPDATE mydb.enrollee_doc_list SET atestat = atest_, passport_copy = pass_cpy_, medical_form = mf_ WHERE id = id_;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `add_enrollee_info` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `add_enrollee_info`(in id_ INT, in f_name_ CHAR(20), in s_name_ CHAR(20), in score_ INT, in spec_ INT)
BEGIN
		INSERT INTO mydb.enrollee_doc_list (id) VALUE (id_);
        insert into mydb.exam_list (id) value (id_);
        insert into mydb.personal_enrollee_information (id) value (id_);
        insert into mydb.enrollee_information (id, first_name, second_name, spec_num, exam_score) values (id_, f_name_, s_name_, spec_, score_);
        
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `add_enrolle_private` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `add_enrolle_private`(in id_ INT, in pas_ BIGINT(20), in dofb_ DATE, in pofb_ CHAR(45), in addr_ CHAR(45))
BEGIN
    UPDATE mydb.personal_enrollee_information SET passport = pas_, date_of_birth = dofb_, place_of_birth = pofb_, address = addr_ WHERE id = id_;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `add_new_spec` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `add_new_spec`(in spec_num_ INT, in spec_ CHAR(45), in bp_ INT, in spp_ INT, in math_ INT, in ph_ INT, in bio_ INT, in chem_ INT, in his_ INT, in rus_ INT, in en_ INT)
BEGIN
        insert into mydb.exam_list (id) value (spec_num_);
        call mydb.add_score(spec_num_, math_, ph_, bio_, chem_, his_, rus_, en_);
        insert into mydb.specialisation_list (spec_num, specialisation, budget_places, self_paid_places) values (spec_num_, spec_, bp_, spp_);
        
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `add_score` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `add_score`(in id_ INT, in math_ INT, in ph_ INT, in bio_ INT, in chem_ INT, in his_ INT, in rus_ INT, in en_ INT)
BEGIN
    UPDATE mydb.exam_list SET math = math_, physics = ph_, biology = bio_, chemestry = chem_, history = his_, russian = rus_, english = en_ WHERE id = id_;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `create_enrollee_user` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `create_enrollee_user`(IN `p_Name` VARCHAR(45), IN `p_Passw` VARCHAR(200))
BEGIN
	DECLARE `_HOST` CHAR(14) DEFAULT '@\'localhost\'';
    SET `p_Name` := CONCAT('\'', REPLACE(TRIM(`p_Name`), CHAR(39), CONCAT(CHAR(92), CHAR(39))), '\''),
    `p_Passw` := CONCAT('\'', REPLACE(`p_Passw`, CHAR(39), CONCAT(CHAR(92), CHAR(39))), '\'');
    SET @`sql` := CONCAT('CREATE USER ', `p_Name`, `_HOST`, ' IDENTIFIED BY ', `p_Passw`);
    PREPARE `stmt` FROM @`sql`;
    EXECUTE `stmt`;
    
    SET @`sql1` := CONCAT('GRANT SELECT ON mydb.enrollee_information TO ', `p_Name`, `_HOST`);
    SET @`sql2` := CONCAT('GRANT SELECT ON mydb.enrollee_doc_list TO ', `p_Name`, `_HOST`);
    SET @`sql3` := CONCAT('GRANT SELECT ON mydb.specialisation_list TO ', `p_Name`, `_HOST`);
    
    PREPARE `stmt` FROM @`sql1`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql2`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql3`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    FLUSH PRIVILEGES;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `create_head_user` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `create_head_user`(IN `p_Name` VARCHAR(45), IN `p_Passw` VARCHAR(200))
BEGIN
	DECLARE `_HOST` CHAR(14) DEFAULT '@\'localhost\'';
    SET `p_Name` := CONCAT('\'', REPLACE(TRIM(`p_Name`), CHAR(39), CONCAT(CHAR(92), CHAR(39))), '\''),
    `p_Passw` := CONCAT('\'', REPLACE(`p_Passw`, CHAR(39), CONCAT(CHAR(92), CHAR(39))), '\'');
    SET @`sql` := CONCAT('CREATE USER ', `p_Name`, `_HOST`, ' IDENTIFIED BY ', `p_Passw`);
    PREPARE `stmt` FROM @`sql`;
    EXECUTE `stmt`;
    
    SET @`sql1` := CONCAT('GRANT SELECT ON mydb.enrollee_information TO ', `p_Name`, `_HOST`);
    SET @`sql2` := CONCAT('GRANT SELECT ON mydb.enrollee_doc_list TO ', `p_Name`, `_HOST`);
    SET @`sql3` := CONCAT('GRANT SELECT, INSERT, UPDATE ON mydb.specialisation_list TO ', `p_Name`, `_HOST`);
    SET @`sql4` := CONCAT('GRANT SELECT ON mydb.personal_enrollee_information TO ', `p_Name`, `_HOST`);
    SET @`sql5` := CONCAT('GRANT SELECT, INSERT, UPDATE ON mydb.exam_list TO ', `p_Name`, `_HOST`);
    
    SET @`sql6` := CONCAT('GRANT EXECUTE ON  PROCEDURE mydb.add_new_spec TO ', `p_Name`, `_HOST`);
    SET @`sql7` := CONCAT('GRANT EXECUTE ON  PROCEDURE mydb.add_score TO ', `p_Name`, `_HOST`);
    
    
    PREPARE `stmt` FROM @`sql1`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql2`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql3`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql4`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
	PREPARE `stmt` FROM @`sql5`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql6`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
        PREPARE `stmt` FROM @`sql7`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql7`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;

    FLUSH PRIVILEGES;

END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `create_officer_user` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `create_officer_user`(IN `p_Name` VARCHAR(45), IN `p_Passw` VARCHAR(200))
BEGIN
	DECLARE `_HOST` CHAR(14) DEFAULT '@\'localhost\'';
    SET `p_Name` := CONCAT('\'', REPLACE(TRIM(`p_Name`), CHAR(39), CONCAT(CHAR(92), CHAR(39))), '\''),
    `p_Passw` := CONCAT('\'', REPLACE(`p_Passw`, CHAR(39), CONCAT(CHAR(92), CHAR(39))), '\'');
    SET @`sql` := CONCAT('CREATE USER ', `p_Name`, `_HOST`, ' IDENTIFIED BY ', `p_Passw`);
    PREPARE `stmt` FROM @`sql`;
    EXECUTE `stmt`;
    
    SET @`sql1` := CONCAT('GRANT SELECT, INSERT, UPDATE ON mydb.enrollee_information TO ', `p_Name`, `_HOST`);
    SET @`sql2` := CONCAT('GRANT SELECT, INSERT, UPDATE ON mydb.enrollee_doc_list TO ', `p_Name`, `_HOST`);
    SET @`sql3` := CONCAT('GRANT SELECT ON mydb.specialisation_list TO ', `p_Name`, `_HOST`);
    SET @`sql4` := CONCAT('GRANT SELECT, INSERT, UPDATE ON mydb.personal_enrollee_information TO ', `p_Name`, `_HOST`);
    SET @`sql5` := CONCAT('GRANT SELECT, INSERT, UPDATE ON mydb.exam_list TO ', `p_Name`, `_HOST`);
    
    SET @`sql6` := CONCAT('GRANT EXECUTE ON  PROCEDURE mydb.add_all_enrollee_info TO ', `p_Name`, `_HOST`);
    SET @`sql7` := CONCAT('GRANT EXECUTE ON  PROCEDURE mydb.add_doc_list TO ', `p_Name`, `_HOST`);
    SET @`sql8` := CONCAT('GRANT EXECUTE ON  PROCEDURE mydb.add_enrollee_info TO ', `p_Name`, `_HOST`);
    SET @`sql9` := CONCAT('GRANT EXECUTE ON  PROCEDURE mydb.add_enrolle_private TO ', `p_Name`, `_HOST`);
    SET @`sql10` := CONCAT('GRANT EXECUTE ON  PROCEDURE mydb.add_score TO ', `p_Name`, `_HOST`);
    
    
    PREPARE `stmt` FROM @`sql1`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql2`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql3`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql4`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
	PREPARE `stmt` FROM @`sql5`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql6`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql7`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql8`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
	PREPARE `stmt` FROM @`sql9`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;
    
    PREPARE `stmt` FROM @`sql10`;
    EXECUTE `stmt`;
    DEALLOCATE PREPARE `stmt`;

    FLUSH PRIVILEGES;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `enrollee_list_by_spec` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `enrollee_list_by_spec`(in var_sp INT)
BEGIN
	select * 
	from mydb.enrollee_information 
		WHERE spec_num=var_sp
		ORDER BY second_name;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-12-01 14:42:31
