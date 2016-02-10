package com.intel.vmf.sample;

import com.intel.vmf.MetadataStream;
import com.intel.vmf.Metadata;
import com.intel.vmf.MetadataSet;
import com.intel.vmf.MetadataDesc;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.channels.FileChannel;

import com.intel.vmf.FieldDesc;
import com.intel.vmf.Variant;
import com.intel.vmf.Vmf;
import com.intel.vmf.MetadataSchema;


public class MetadataManipulation
{  
    protected final static String srcFile = "BlueSquare.avi";
    protected final static String dstFile = "test.avi";
    
    protected static void copy (String srcFile, String dstFile) throws IOException 
    {
        FileInputStream fileInputStream = new FileInputStream(srcFile);
        FileChannel srcChannel = fileInputStream.getChannel();
            
        FileOutputStream fileOutputStream = new FileOutputStream(dstFile);
        FileChannel dstChannel = fileOutputStream.getChannel();

        dstChannel.transferFrom(srcChannel, 0, srcChannel.size());

        srcChannel.close();
        dstChannel.close();
        fileInputStream.close();
        fileOutputStream.close();
    }
    
    protected static MetadataStream stream;
    static protected MetadataSchema schema1;
    static protected MetadataSchema schema2;
    
    static protected MetadataDesc mdDesc1;
    static protected MetadataDesc mdDesc2;
    
    static protected FieldDesc fields1[];
    static protected FieldDesc fields2[];
       
    public static void addMetadata (String dstFile) throws IOException
    {
        System.out.println("\nAdd metadata.\n" + "[stream]: " + dstFile + "\n");
        
        copy(srcFile, dstFile);
        
        stream = new MetadataStream ();
        schema1 = new MetadataSchema("first_schema");
        schema2 = new MetadataSchema("second_schema");
        
        fields1 = new FieldDesc [3];
        fields2 = new FieldDesc [4];
        
        fields1[0] = new FieldDesc ("name", Variant.type_string, false);
        fields1[1] = new FieldDesc ("last name", Variant.type_string, false);
        fields1[2] = new FieldDesc ("age", Variant.type_integer, false);
        
        fields2[0] = new FieldDesc ("manufacturer", Variant.type_string, false);
        fields2[1] = new FieldDesc ("model", Variant.type_string, false);
        fields2[2] = new FieldDesc ("number", Variant.type_string, false);
        fields2[3] = new FieldDesc ("age", Variant.type_integer, false);
        
        mdDesc1 = new MetadataDesc ("person", fields1);
        mdDesc2 = new MetadataDesc ("car", fields2);
        
        schema1.add(mdDesc1);
        schema2.add(mdDesc2);
        
        if (!stream.open (dstFile, MetadataStream.ReadWrite))
            throw new java.lang.UnsupportedOperationException("Can't open MetadataStream.");
        
        stream.addSchema(schema1);
        stream.addSchema(schema2);
        
        Metadata md1 = new Metadata (mdDesc1);
        Metadata md2 = new Metadata (mdDesc1);
        Metadata md3 = new Metadata (mdDesc2);
        
        Variant var1 = new Variant ("Dmitry");
        Variant var2 = new Variant ("Bogdanov");
        Variant var3 = new Variant (21);
        
        md1.setFieldValue("name", var1);
        md1.setFieldValue("last name", var2);
        md1.setFieldValue("age", var3);
        
        stream.add(md1);
        
        var1.setTo ("Anna");
        var2.setTo ("Plyakina");
        var3.setTo (26);
        
        md2.setFieldValue("name", var1);
        md2.setFieldValue("last name", var2);
        md2.setFieldValue("age", var3);
        
        stream.add(md2);
        
        var1.setTo("Chevrolet");
        var2.setTo("Aveo");
        var3.setTo("n700nn777");
        Variant var4 = new Variant (1);
        
        md3.setFieldValue("manufacturer", var1);
        md3.setFieldValue("model", var2);
        md3.setFieldValue("number", var3);
        md3.setFieldValue("age", var4);
        
        stream.add(md3);
        
        stream.save();
        stream.close();
    }
    
    public static void printMetadataStructure() throws IOException 
    {
        System.out.println("\nPrinting metadata structure.\n" + "[stream]: " + dstFile + "\n");
        
        if (!stream.open (dstFile, MetadataStream.ReadOnly))
            throw new java.lang.UnsupportedOperationException("Can't open MetadataStream.");
     
        String[] sNames = stream.getAllSchemaNames();
        for (int sNum = 0; sNum < sNames.length; sNum++)
        {
            String sName = sNames[sNum];
            
            System.out.println("\t* (" + sNum + ") [schema]: " + sName  + "\n");
            
            if(!stream.load(sName))
                throw new java.lang.UnsupportedOperationException("Error loading schema:" + sName);
                
            MetadataDesc mDescs[] = stream.getSchema(sName).getAll();
            
            for (int setNum = 0; setNum < mDescs.length; setNum++)
            {
                MetadataDesc mDesc = mDescs[setNum];
                String setName = mDesc.getMetadataName();
                MetadataSet mdSet = stream.queryByName(setName);
                long setSize = mdSet.getSize ();
                String fieldsString = "";
                String separator = "";
                FieldDesc fields[] = mDesc.getFields();
                
                for (int i = 0; i < fields.length; i++)
                {
                    fieldsString += separator + fields[i].getName();
                    separator = ",";
                }
               
                System.out.println("\t\t* (" + sNum + "." + setNum + ") [set]: " + setName + "(" + setSize + " items)" + " {" + fieldsString + "}"  + "\n");
            }
        }
        
        stream.close();
    }

    public static void removeMetadata (String schemaName, String setName)
    {
        System.out.println("\nRemoving metadata:\n" + "[stream]: " + dstFile + "\n" + 
        (schemaName.isEmpty() ? "*" : schemaName + '/' + (setName.isEmpty() ? "*" : setName) ) + "\n");
        
        if (!stream.open (dstFile, MetadataStream.ReadWrite))
            throw new java.lang.UnsupportedOperationException("Can't open MetadataStream.");
        
        if(!stream.load(schemaName))
            throw new java.lang.UnsupportedOperationException("Error loading schema:" + schemaName);
        
        if (schemaName.isEmpty())
        {
            stream.remove();
        }
        else
        {
            if(setName.isEmpty())
            {
                stream.remove (stream.getSchema(schemaName));
            }
            else
            {
                MetadataSet mdSet = stream.queryByName(setName);
                stream.remove(mdSet);
            }
        }
        
        stream.save();
        stream.close();
    }
    
    
    
    public static void main (String[] args) throws IOException 
    {
        Vmf.initialize();
        
        addMetadata (dstFile);
        
        printMetadataStructure ();
        
        removeMetadata("first_schema", "person");
        
        Vmf.terminate ();
    }

}