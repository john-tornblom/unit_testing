/*----------------------------------------------------------------------------
 * Description:
 * Methods for bridging to an external entity.
 *
 * External Entity:  Inter_Process_Communication (Unit_Test_IPC)
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

import java.io.PrintStream;

public class Unit_Testing_IPC {

	private static PrintStream out = null;
	private static PrintStream err = null;

	static {
		try {
			Class<?> cls = Class.forName("org.xtuml.bp.core.CorePlugin");
			out = (PrintStream) cls.getField("out").get(null);
			err = (PrintStream) cls.getField("err").get(null);
		} catch (Throwable t) {
			out = System.out;
			err = System.err;
		}
	}

	public static int Get_Process_Id() {
		return 1;
	}

	public static void Pipe(BPInteger fd1, BPInteger fd2) {
		
	}

	public static void Close(int fd) {
	}

	public static int Fork() {
		return 0;
	}

	public static boolean Wait(int process_id) {
		return false;
	}

	public static boolean Send_Message(int fd, int type, String value) {
		switch (type) {
		case 0:
			out.println("Assertion PASSED: " + value);
			break;
		case 1:
			err.println("Assertion FAILED: " + value);
			break;
		case 2:
			err.println("Execution ERROR: " + value);
			break;
		case 3:
			Exit();
			break;
		}
		return true;
	}

	//public static boolean Receive_Message(int fd, BPInteger type, BPString value) { 
	//	return false; 
	//}

	public static void Exit() {
		try {
			//out.println("Execution engine cannot restore test fixture for next test case, terminating");
			//Class<?> cls = Class.forName("lib.ARCH");
			//cls.getMethod("shutdown").invoke(null);
		} catch (Exception ex) {
		}
	}
}
