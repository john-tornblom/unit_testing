/*----------------------------------------------------------------------------
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  Unit_Test_String_Rendering (Unit_Test_String_Rendering)
 * 
 * Copyright 2017 John Törnblom
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *--------------------------------------------------------------------------*/

package lib;

public class Unit_Testing_String_Rendering {

	public static String Render_ASCII(int value) {
		try {
			return String.valueOf(Character.toChars(value));
		} catch (Exception ex) {
			return "";
		}
	}

	public static String Render_Integer(int value) {
		return new Integer(value).toString();
	}

	public static String Replace(String str, String old, String new_) {
		try {
			return str.replace(old, new_);
		} catch (Exception ex) {
			return str;
		}
	}
}
