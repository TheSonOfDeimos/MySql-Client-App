-- MySQL dump 10.13  Distrib 8.0.17, for macos10.14 (x86_64)
--
-- Host: localhost    Database: mydb
-- ------------------------------------------------------
-- Server version	8.0.17

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
INSERT INTO `enrollee_doc_list` VALUES (1,NULL,NULL,NULL),(2,NULL,NULL,NULL),(3,NULL,NULL,NULL),(4,NULL,NULL,NULL),(5,NULL,NULL,NULL),(6,NULL,NULL,NULL),(7,NULL,NULL,NULL),(8,NULL,NULL,NULL);
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
INSERT INTO `enrollee_information` VALUES (1,'Lev','Kargalov',11,198),(2,'Margarita','Los',11,250),(3,'Nick','Morozov',23,230),(4,'Oleg','Nikiforov',911,251),(5,'Mark','Volovec',911,210),(6,'Anton','Volkov',23,178),(7,'Vladislav','Antonov',23,310),(8,'Maxim','Vlasov',11,256);
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
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `exam_list`
--

LOCK TABLES `exam_list` WRITE;
/*!40000 ALTER TABLE `exam_list` DISABLE KEYS */;
INSERT INTO `exam_list` VALUES (1,NULL,NULL,NULL,NULL),(2,NULL,NULL,NULL,NULL),(3,NULL,NULL,NULL,NULL),(4,NULL,NULL,NULL,NULL),(5,NULL,NULL,NULL,NULL),(6,NULL,NULL,NULL,NULL),(7,NULL,NULL,NULL,NULL),(8,NULL,NULL,NULL,NULL),(11,NULL,NULL,NULL,NULL),(23,NULL,NULL,NULL,NULL),(856,75,75,0,0),(911,45,0,100,100),(2342,10,10,10,10);
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
INSERT INTO `personal_enrollee_information` VALUES (1,4019430017,'1999-07-28','Blagoveschensk','Kupchinskaya 25/11'),(2,NULL,NULL,NULL,NULL),(3,0,'1999-09-11','Saint-Petersburg','Here'),(4,0,'1998-11-23','Tambov','Moscowsy pr. 23'),(5,0,'2000-11-23','Zeya','Svetly 49'),(6,235332,'1992-08-11','Vologda','Marata 34/7'),(7,20455,'1989-11-14','London','Bucengem Palace'),(8,2345622,'1999-10-24','Kaliningrad','Harchenko 59');
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
INSERT INTO `specialisation_list` VALUES (11,'Programming',45,80),(23,'Menegmant',50,50),(856,'Engeneer',234,500),(911,'Dantist',2,200),(2342,'Veterenar',100,10);
/*!40000 ALTER TABLE `specialisation_list` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping events for database 'mydb'
--

--
-- Dumping routines for database 'mydb'
--
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
CREATE DEFINER=`root`@`localhost` PROCEDURE `add_new_spec`(in spec_num_ INT, in spec_ CHAR(45), in bp_ INT, in spp_ INT, in math_ INT, in ph_ INT, in bio_ INT, in chem_ INT)
BEGIN
        insert into mydb.exam_list (id) value (spec_num_);
        call mydb.add_score(spec_num_, math_, ph_, bio_, chem_);
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
CREATE DEFINER=`root`@`localhost` PROCEDURE `add_score`(in id_ INT, in math_ INT, in ph_ INT, in bio_ INT, in chem_ INT)
BEGIN
    UPDATE mydb.exam_list SET math = math_, physics = ph_, biology = bio_, chemestry = chem_ WHERE id = id_;
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

-- Dump completed on 2019-11-09 15:12:12
